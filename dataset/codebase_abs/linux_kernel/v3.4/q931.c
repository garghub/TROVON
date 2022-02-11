void
F_1 ( T_1 * V_1 , T_1 * V_2 , int V_3 )
{
T_1 * V_4 ;
int V_5 ;
V_4 = V_2 + V_3 + 2 ;
V_5 = V_2 [ 1 ] - V_3 ;
while ( V_5 -- )
* V_1 ++ = * V_4 ++ ;
* V_1 ++ = '\0' ;
}
static int
F_2 ( char * V_1 , T_1 V_6 , int V_7 , int V_8 )
{
char * V_9 = V_1 ;
V_6 = V_6 << ( 8 - V_7 ) ;
while ( V_8 -- ) {
if ( V_6 & 0x80 )
* V_9 ++ = '1' ;
else
* V_9 ++ = '0' ;
V_6 = V_6 << 1 ;
}
return ( V_9 - V_1 ) ;
}
static
T_1 *
F_3 ( T_1 * V_4 )
{
while ( ! ( * V_4 ++ & 0x80 ) ) ;
return ( V_4 ) ;
}
static
int
F_4 ( char * V_1 , T_1 * V_4 )
{
T_1 * V_10 ;
char * V_9 = V_1 ;
int V_11 , V_12 ;
V_10 = V_4 + V_4 [ 1 ] + 1 ;
V_4 += 2 ;
V_9 += sprintf ( V_9 , L_1 ) ;
V_9 += F_2 ( V_9 , * V_4 , 7 , 2 ) ;
V_9 += sprintf ( V_9 , L_2 ) ;
V_9 += F_2 ( V_9 , * V_4 , 4 , 4 ) ;
* V_9 ++ = '\n' ;
V_4 = F_3 ( V_4 ) ;
V_12 = 0x7f & * V_4 ++ ;
for ( V_11 = 0 ; V_11 < V_13 ; V_11 ++ )
if ( V_14 [ V_11 ] . V_15 == V_12 )
break;
if ( V_11 == V_13 )
V_9 += sprintf ( V_9 , L_3 , V_12 ) ;
else
V_9 += sprintf ( V_9 , L_4 , V_12 , V_14 [ V_11 ] . V_16 ) ;
while ( ! 0 ) {
if ( V_4 > V_10 )
break;
V_9 += sprintf ( V_9 , L_5 , * V_4 ++ & 0x7f ) ;
V_9 += sprintf ( V_9 , L_6 , * V_4 & 0x7f ) ;
if ( * V_4 & 0x80 ) {
* V_9 ++ = '\n' ;
break;
} else
V_9 += sprintf ( V_9 , L_7 , ( * ++ V_4 ) & 0x7f ) ;
}
return ( V_9 - V_1 ) ;
}
static int
F_5 ( char * V_1 , T_1 * V_4 )
{
char * V_9 = V_1 ;
int V_11 , V_12 ;
V_4 ++ ;
if ( 0 == * V_4 ) {
V_9 += sprintf ( V_9 , L_8 ) ;
return ( V_9 - V_1 ) ;
} else if ( * V_4 > 1 ) {
V_9 += sprintf ( V_9 , L_1 ) ;
V_9 += F_2 ( V_9 , V_4 [ 2 ] , 7 , 2 ) ;
V_9 += sprintf ( V_9 , L_2 ) ;
V_9 += F_2 ( V_9 , V_4 [ 2 ] , 4 , 4 ) ;
* V_9 ++ = '\n' ;
}
V_4 ++ ;
V_12 = 0x7f & * V_4 ;
for ( V_11 = 0 ; V_11 < V_17 ; V_11 ++ )
if ( V_18 [ V_11 ] . V_15 == V_12 )
break;
if ( V_11 == V_17 )
V_9 += sprintf ( V_9 , L_3 , V_12 ) ;
else
V_9 += sprintf ( V_9 , L_4 , V_12 , V_18 [ V_11 ] . V_19 ) ;
return ( V_9 - V_1 ) ;
}
static int
F_6 ( char * V_1 , T_1 * V_4 )
{
char * V_9 = V_1 ;
V_4 += 2 ;
V_9 += sprintf ( V_9 , L_9 ) ;
V_9 += F_2 ( V_9 , * V_4 , 8 , 8 ) ;
* V_9 ++ = '\n' ;
return ( V_9 - V_1 ) ;
}
static int
F_7 ( char * V_1 , T_1 * V_4 )
{
int V_5 ;
char * V_9 = V_1 ;
V_4 ++ ;
V_5 = * V_4 ++ - 1 ;
V_9 += sprintf ( V_9 , L_9 ) ;
V_9 += F_2 ( V_9 , * V_4 ++ , 8 , 8 ) ;
* V_9 ++ = '\n' ;
V_9 += sprintf ( V_9 , L_10 ) ;
while ( V_5 -- )
* V_9 ++ = * V_4 ++ ;
* V_9 ++ = '\n' ;
return ( V_9 - V_1 ) ;
}
static int
F_8 ( char * V_1 , T_1 * V_4 )
{
int V_5 ;
char * V_9 = V_1 ;
V_4 ++ ;
V_5 = * V_4 ++ - 1 ;
V_9 += sprintf ( V_9 , L_9 ) ;
V_9 += F_2 ( V_9 , * V_4 , 8 , 8 ) ;
* V_9 ++ = '\n' ;
if ( ! ( * V_4 & 0x80 ) ) {
V_9 += sprintf ( V_9 , L_11 ) ;
V_9 += F_2 ( V_9 , * ++ V_4 , 8 , 8 ) ;
* V_9 ++ = '\n' ;
V_5 -- ;
} ;
V_4 ++ ;
V_9 += sprintf ( V_9 , L_10 ) ;
while ( V_5 -- )
* V_9 ++ = * V_4 ++ ;
* V_9 ++ = '\n' ;
return ( V_9 - V_1 ) ;
}
static
int
F_9 ( char * V_1 , T_1 * V_4 )
{
char * V_9 = V_1 , V_20 ;
V_4 += 2 ;
V_9 += sprintf ( V_9 , L_12 ) ;
V_9 += F_2 ( V_9 , * V_4 ++ , 8 , 8 ) ;
* V_9 ++ = '\n' ;
V_9 += sprintf ( V_9 , L_13 ) ;
V_9 += F_2 ( V_9 , * V_4 , 8 , 8 ) ;
* V_9 ++ = '\n' ;
if ( ( * V_4 ++ & 0x1f ) == 0x18 ) {
V_9 += sprintf ( V_9 , L_14 ) ;
V_9 += F_2 ( V_9 , * V_4 ++ , 8 , 8 ) ;
* V_9 ++ = '\n' ;
}
if ( ( * V_4 & 0x60 ) == 0x20 ) {
V_20 = ' ' ;
do {
V_9 += sprintf ( V_9 , L_15 , V_20 ) ;
V_9 += F_2 ( V_9 , * V_4 , 8 , 8 ) ;
* V_9 ++ = '\n' ;
if ( V_20 == ' ' )
V_20 = 'a' ;
else
V_20 ++ ;
}
while ( ! ( * V_4 ++ & 0x80 ) );
}
if ( ( * V_4 & 0x60 ) == 0x40 ) {
V_9 += sprintf ( V_9 , L_16 ) ;
V_9 += F_2 ( V_9 , * V_4 ++ , 8 , 8 ) ;
* V_9 ++ = '\n' ;
}
if ( ( * V_4 & 0x60 ) == 0x60 ) {
V_9 += sprintf ( V_9 , L_17 ) ;
V_9 += F_2 ( V_9 , * V_4 ++ , 8 , 8 ) ;
* V_9 ++ = '\n' ;
}
return ( V_9 - V_1 ) ;
}
static
int
F_10 ( char * V_1 , T_1 * V_4 )
{
char * V_9 = V_1 ;
T_1 V_8 ;
V_4 ++ ;
V_8 = * V_4 ++ ;
V_9 += sprintf ( V_9 , L_12 ) ;
V_9 += F_2 ( V_9 , * V_4 , 8 , 8 ) ;
switch ( * V_4 ++ ) {
case 0x80 :
V_9 += sprintf ( V_9 , L_18 ) ;
break;
case 0x88 :
V_9 += sprintf ( V_9 , L_19 ) ;
break;
case 0x90 :
V_9 += sprintf ( V_9 , L_20 ) ;
break;
default:
V_9 += sprintf ( V_9 , L_21 ) ;
}
* V_9 ++ = '\n' ;
V_9 += sprintf ( V_9 , L_13 ) ;
V_9 += F_2 ( V_9 , * V_4 , 8 , 8 ) ;
switch ( * V_4 ++ ) {
case 0x90 :
V_9 += sprintf ( V_9 , L_22 ) ;
break;
case 0xc0 :
V_9 += sprintf ( V_9 , L_23 ) ;
break;
default:
V_9 += sprintf ( V_9 , L_24 ) ;
}
* V_9 ++ = '\n' ;
if ( V_8 > 2 ) {
V_9 += sprintf ( V_9 , L_25 ) ;
V_9 += F_2 ( V_9 , * V_4 , 8 , 8 ) ;
switch ( * V_4 ++ ) {
case 0x21 :
V_9 += sprintf ( V_9 , L_26 ) ;
V_9 += sprintf ( V_9 , L_27 ) ;
V_9 += F_2 ( V_9 , * V_4 , 8 , 8 ) ;
break;
case 0xa2 :
V_9 += sprintf ( V_9 , L_28 ) ;
break;
default:
V_9 += sprintf ( V_9 , L_29 ) ;
}
* V_9 ++ = '\n' ;
}
return ( V_9 - V_1 ) ;
}
static int
F_11 ( char * V_1 , T_1 * V_4 )
{
char * V_9 = V_1 ;
char V_20 = ' ' ;
int V_5 , V_21 = 3 ;
V_4 ++ ;
V_5 = * V_4 ++ ;
while ( V_5 -- ) {
V_9 += sprintf ( V_9 , L_30 , V_21 , V_20 ) ;
V_9 += F_2 ( V_9 , * V_4 ++ , 8 , 8 ) ;
* V_9 ++ = '\n' ;
if ( * V_4 & 0x80 ) {
V_21 ++ ;
V_20 = ' ' ;
} else if ( V_20 == ' ' )
V_20 = 'a' ;
else
V_20 ++ ;
}
return ( V_9 - V_1 ) ;
}
static int
F_12 ( char * V_1 , T_1 * V_4 )
{
char * V_9 = V_1 ;
char V_20 = ' ' ;
int V_5 , V_21 = 3 ;
V_4 ++ ;
V_5 = * V_4 ++ ;
while ( V_5 -- ) {
V_9 += sprintf ( V_9 , L_30 , V_21 , V_20 ) ;
V_9 += F_2 ( V_9 , * V_4 , 8 , 8 ) ;
* V_9 ++ = '\n' ;
if ( * V_4 ++ & 0x80 ) {
V_21 ++ ;
V_20 = ' ' ;
} else if ( V_20 == ' ' )
V_20 = 'a' ;
else
V_20 ++ ;
}
return ( V_9 - V_1 ) ;
}
static int
F_13 ( char * V_1 , T_1 * V_4 )
{
char * V_9 = V_1 ;
int V_5 ;
V_4 ++ ;
V_5 = * V_4 ++ - 1 ;
V_9 += sprintf ( V_9 , L_31 ) ;
V_9 += F_2 ( V_9 , * V_4 ++ , 8 , 8 ) ;
V_9 += sprintf ( V_9 , L_32 ) ;
while ( V_5 -- )
* V_9 ++ = * V_4 ++ ;
* V_9 ++ = '\n' ;
return ( V_9 - V_1 ) ;
}
static int
F_14 ( char * V_1 , T_1 * V_4 )
{
char * V_9 = V_1 ;
int V_5 ;
V_4 ++ ;
V_5 = * V_4 ++ ;
V_9 += sprintf ( V_9 , L_33 ) ;
while ( V_5 -- )
* V_9 ++ = * V_4 ++ ;
* V_9 ++ = '\n' ;
return ( V_9 - V_1 ) ;
}
static int
F_15 ( char * V_1 , T_1 * V_4 )
{
char * V_9 = V_1 ;
V_4 += 2 ;
V_9 += sprintf ( V_9 , L_12 ) ;
V_9 += F_2 ( V_9 , * V_4 , 8 , 8 ) ;
* V_9 ++ = '\n' ;
if ( ! ( * V_4 ++ & 80 ) ) {
V_9 += sprintf ( V_9 , L_13 ) ;
V_9 += F_2 ( V_9 , * V_4 ++ , 8 , 8 ) ;
* V_9 ++ = '\n' ;
}
V_9 += sprintf ( V_9 , L_34 ) ;
switch ( * V_4 ) {
case 0 :
V_9 += sprintf ( V_9 , L_35 ) ;
break;
case 1 :
V_9 += sprintf ( V_9 , L_36 ) ;
break;
case 2 :
V_9 += sprintf ( V_9 , L_37 ) ;
break;
case 3 :
V_9 += sprintf ( V_9 , L_38 ) ;
break;
default:
V_9 += sprintf ( V_9 , L_39 ) ;
break;
}
* V_9 ++ = '\n' ;
return ( V_9 - V_1 ) ;
}
static int
F_16 ( char * V_1 , T_1 * V_4 )
{
char * V_9 = V_1 ;
int V_5 , V_22 , V_8 , V_11 ;
V_4 ++ ;
V_5 = * V_4 ++ - 1 ;
if ( * V_4 ++ != 0x80 ) {
V_9 += sprintf ( V_9 , L_40 ) ;
return ( V_9 - V_1 ) ;
}
while ( V_5 > 0 ) {
V_22 = * V_4 ++ ;
V_8 = * V_4 ++ ;
V_5 -= V_8 + 2 ;
if ( ( V_22 == 0x80 ) || ( V_22 == 0x81 ) ) V_4 ++ ;
else {
for ( V_11 = 0 ; V_11 < V_23 ; V_11 ++ )
if ( V_22 == V_24 [ V_11 ] . V_15 )
break;
if ( V_11 != V_23 ) {
V_9 += sprintf ( V_9 , L_41 , V_24 [ V_11 ] . V_19 ) ;
while ( V_8 -- )
* V_9 ++ = * V_4 ++ ;
} else {
V_9 += sprintf ( V_9 , L_42 , V_22 ) ;
while ( V_8 -- )
* V_9 ++ = * V_4 ++ ;
}
V_9 += sprintf ( V_9 , L_43 ) ;
}
}
return ( V_9 - V_1 ) ;
}
static int
F_17 ( char * V_1 , T_1 * V_4 )
{
char * V_9 = V_1 ;
char V_20 = ' ' ;
int V_5 , V_21 = 3 ;
V_4 ++ ;
V_5 = * V_4 ++ ;
V_9 += sprintf ( V_9 , L_44 ) ;
while ( V_5 -- ) {
V_9 += sprintf ( V_9 , L_45 , * V_4 ++ ) ;
if ( * V_4 & 0x80 ) {
V_21 ++ ;
V_20 = ' ' ;
} else if ( V_20 == ' ' )
V_20 = 'a' ;
else
V_20 ++ ;
}
* V_9 ++ = '\"' ;
* V_9 ++ = '\n' ;
return ( V_9 - V_1 ) ;
}
static int
F_18 ( char * V_1 , T_1 * V_4 )
{
char * V_9 = V_1 ;
int V_5 , V_25 ;
V_4 ++ ;
V_5 = * V_4 ++ ;
V_9 += sprintf ( V_9 , L_9 ) ;
V_9 += F_2 ( V_9 , * V_4 ++ , 8 , 8 ) ;
V_9 += sprintf ( V_9 , L_43 ) ;
V_5 -= 1 ;
while ( V_5 > 0 ) {
V_9 += sprintf ( V_9 , L_46 ) ;
V_9 += F_2 ( V_9 , * V_4 ++ , 8 , 8 ) ;
V_9 += sprintf ( V_9 , L_43 ) ;
V_9 += sprintf ( V_9 , L_47 , V_25 = * V_4 ++ & 0x7f ) ;
V_5 -= 2 ;
V_9 += sprintf ( V_9 , L_48 ) ;
while ( V_25 -- ) {
V_9 += sprintf ( V_9 , L_49 , * V_4 ++ ) ;
V_5 -- ;
}
V_9 += sprintf ( V_9 , L_43 ) ;
}
return ( V_9 - V_1 ) ;
}
int
F_19 ( char * V_26 , T_1 * V_4 , int V_27 )
{
register int V_11 ;
register char * V_28 = V_26 ;
for ( V_11 = 0 ; V_11 < V_27 ; V_11 ++ ) {
* V_28 ++ = ' ' ;
* V_28 ++ = F_20 ( V_4 [ V_11 ] ) ;
* V_28 ++ = F_21 ( V_4 [ V_11 ] ) ;
}
* V_28 ++ = 0 ;
return ( V_28 - V_26 ) ;
}
void
F_22 ( struct V_29 * V_30 , T_1 * V_31 , int V_32 )
{
char * V_9 ;
if ( V_32 < 1 )
return;
V_9 = V_30 -> V_33 ;
if ( V_32 < V_34 / 3 - 10 ) {
* V_9 ++ = 'H' ;
* V_9 ++ = 'E' ;
* V_9 ++ = 'X' ;
* V_9 ++ = ':' ;
V_9 += F_19 ( V_9 , V_31 , V_32 ) ;
V_9 -- ;
* V_9 ++ = '\n' ;
* V_9 = 0 ;
F_23 ( V_30 , NULL , V_30 -> V_33 ) ;
} else
F_23 ( V_30 , L_50 , L_51 , V_32 ) ;
}
void
F_24 ( struct V_29 * V_30 , struct V_35 * V_36 , int V_37 )
{
T_1 * V_38 , * V_31 ;
char * V_9 ;
unsigned char V_39 , V_40 , V_41 , V_42 ;
unsigned char V_43 , V_44 , V_45 ;
int V_11 , V_46 = 0 , V_47 = 0 , V_48 = 0 ;
int V_32 , V_49 = 0 ;
if ( V_36 -> V_8 < 3 )
return;
V_9 = V_30 -> V_33 ;
V_9 += F_25 ( V_9 , V_50 ) ;
* V_9 ++ = ' ' ;
V_43 = V_36 -> V_51 [ 0 ] >> 2 ;
V_44 = V_36 -> V_51 [ 1 ] >> 1 ;
V_45 = V_36 -> V_51 [ 2 ] ;
V_31 = V_36 -> V_51 ;
V_9 += sprintf ( V_9 , L_52 , V_37 ? L_53 : L_54 ) ;
V_32 = V_36 -> V_8 ;
if ( V_44 == V_52 ) {
if ( V_43 == V_53 ) {
if ( V_45 == 3 ) {
V_9 += sprintf ( V_9 , L_55 ) ;
V_31 += 3 ;
V_32 -= 3 ;
} else {
V_9 += sprintf ( V_9 , L_56 ) ;
V_49 = 1 ;
}
} else if ( V_43 == V_54 ) {
V_9 += sprintf ( V_9 , L_57 ) ;
V_49 = 1 ;
} else {
V_9 += sprintf ( V_9 , L_58 , V_43 ) ;
V_49 = 1 ;
}
} else {
if ( V_43 == V_53 ) {
if ( ! ( V_45 & 1 ) ) {
V_9 += sprintf ( V_9 , L_59 , V_44 ) ;
V_31 += 4 ;
V_32 -= 4 ;
} else {
V_9 += sprintf ( V_9 , L_60 , V_44 ) ;
V_49 = 1 ;
}
} else {
V_9 += sprintf ( V_9 , L_61 , V_43 , V_44 ) ;
V_49 = 1 ;
}
}
V_38 = V_36 -> V_51 + V_36 -> V_8 ;
if ( V_31 >= V_38 ) {
V_9 += sprintf ( V_9 , L_62 ) ;
V_49 = 1 ;
}
if ( V_49 ) {
* V_9 = 0 ;
F_23 ( V_30 , NULL , V_30 -> V_33 ) ;
return;
}
if ( ( 0xfe & V_31 [ 0 ] ) == V_55 ) {
V_39 = * V_31 ++ ;
V_40 = * V_31 ++ ;
if ( V_40 )
V_41 = * V_31 ++ ;
else
V_41 = 0 ;
V_42 = * V_31 ++ ;
if ( V_39 == V_55 ) {
for ( V_11 = 0 ; V_11 < V_56 ; V_11 ++ )
if ( V_57 [ V_11 ] . V_15 == V_42 )
break;
if ( V_11 == V_56 )
V_9 += sprintf ( V_9 , L_63 ,
V_41 & 0x7f , ( V_41 & 0x80 ) ? L_64 : L_65 ,
V_32 , V_42 ) ;
else
V_9 += sprintf ( V_9 , L_66 ,
V_41 & 0x7f , ( V_41 & 0x80 ) ? L_64 : L_65 ,
V_32 , V_57 [ V_11 ] . V_19 ) ;
} else {
for ( V_11 = 0 ; V_11 < V_58 ; V_11 ++ )
if ( V_59 [ V_11 ] . V_15 == V_42 )
break;
if ( V_11 == V_58 )
V_9 += sprintf ( V_9 , L_67 ,
V_41 & 0x7f , ( V_41 & 0x80 ) ? L_64 : L_65 ,
V_32 , V_42 ) ;
else
V_9 += sprintf ( V_9 , L_66 ,
V_41 & 0x7f , ( V_41 & 0x80 ) ? L_64 : L_65 ,
V_32 , V_59 [ V_11 ] . V_19 ) ;
}
while ( V_31 < V_38 ) {
if ( * V_31 & 0x80 ) {
switch ( ( * V_31 >> 4 ) & 7 ) {
case 1 :
V_9 += sprintf ( V_9 , L_68 , * V_31 & 0xf ) ;
V_47 = V_46 ;
V_46 = * V_31 & 7 ;
V_48 = * V_31 & 8 ;
break;
case 3 :
V_9 += sprintf ( V_9 , L_69 , * V_31 & 0xf ) ;
break;
case 2 :
if ( * V_31 == 0xa0 ) {
V_9 += sprintf ( V_9 , L_70 ) ;
break;
}
if ( * V_31 == 0xa1 ) {
V_9 += sprintf ( V_9 , L_71 ) ;
}
break;
default:
V_9 += sprintf ( V_9 , L_72 , * V_31 ) ;
break;
}
V_31 ++ ;
continue;
}
if ( V_46 == 0 ) {
for ( V_11 = 0 ; V_11 < V_60 ; V_11 ++ )
if ( * V_31 == V_61 [ V_11 ] . V_15 )
break;
if ( V_11 != V_60 ) {
V_9 += sprintf ( V_9 , L_73 , V_61 [ V_11 ] . V_19 ) ;
V_9 += V_61 [ V_11 ] . F_26 ( V_9 , V_31 ) ;
} else
V_9 += sprintf ( V_9 , L_74 , V_46 , * V_31 , V_31 [ 1 ] ) ;
} else if ( V_46 == 6 ) {
for ( V_11 = 0 ; V_11 < V_62 ; V_11 ++ )
if ( * V_31 == V_63 [ V_11 ] . V_15 )
break;
if ( V_11 != V_62 ) {
V_9 += sprintf ( V_9 , L_73 , V_63 [ V_11 ] . V_19 ) ;
V_9 += V_63 [ V_11 ] . F_26 ( V_9 , V_31 ) ;
} else
V_9 += sprintf ( V_9 , L_74 , V_46 , * V_31 , V_31 [ 1 ] ) ;
} else
V_9 += sprintf ( V_9 , L_75 , V_46 , * V_31 , V_31 [ 1 ] ) ;
if ( V_48 == 8 ) {
V_46 = V_47 ;
V_47 = 0 ;
V_48 = 0 ;
}
V_31 += V_31 [ 1 ] + 2 ;
}
} else if ( ( V_31 [ 0 ] == 8 ) && ( V_30 -> V_64 == V_65 ) ) {
V_31 ++ ;
V_40 = * V_31 ++ ;
if ( V_40 )
V_41 = * V_31 ++ ;
else
V_41 = 0 ;
V_42 = * V_31 ++ ;
for ( V_11 = 0 ; V_11 < V_66 ; V_11 ++ )
if ( V_67 [ V_11 ] . V_15 == V_42 )
break;
if ( V_11 == V_66 )
V_9 += sprintf ( V_9 , L_76 ,
V_41 & 0x7f , ( V_41 & 0x80 ) ? L_64 : L_65 ,
V_32 , V_42 ) ;
else
V_9 += sprintf ( V_9 , L_66 ,
V_41 & 0x7f , ( V_41 & 0x80 ) ? L_64 : L_65 ,
V_32 , V_67 [ V_11 ] . V_19 ) ;
while ( V_31 < V_38 ) {
if ( * V_31 & 0x80 ) {
switch ( ( * V_31 >> 4 ) & 7 ) {
case 1 :
V_9 += sprintf ( V_9 , L_68 , * V_31 & 0xf ) ;
V_47 = V_46 ;
V_46 = * V_31 & 7 ;
V_48 = * V_31 & 8 ;
break;
default:
V_9 += sprintf ( V_9 , L_77 , * V_31 ) ;
break;
}
V_31 ++ ;
continue;
}
if ( V_46 == 0 ) {
for ( V_11 = 0 ; V_11 < V_68 ; V_11 ++ )
if ( * V_31 == V_69 [ V_11 ] . V_15 )
break;
if ( V_11 != V_68 ) {
V_9 += sprintf ( V_9 , L_73 , V_69 [ V_11 ] . V_19 ) ;
V_9 += V_69 [ V_11 ] . F_26 ( V_9 , V_31 ) ;
} else
V_9 += sprintf ( V_9 , L_78 , * V_31 , V_31 [ 1 ] ) ;
} else if ( V_46 == 5 ) {
for ( V_11 = 0 ; V_11 < V_70 ; V_11 ++ )
if ( * V_31 == V_71 [ V_11 ] . V_15 )
break;
if ( V_11 != V_70 ) {
V_9 += sprintf ( V_9 , L_73 , V_71 [ V_11 ] . V_19 ) ;
V_9 += V_71 [ V_11 ] . F_26 ( V_9 , V_31 ) ;
} else
V_9 += sprintf ( V_9 , L_78 , * V_31 , V_31 [ 1 ] ) ;
} else if ( V_46 == 6 ) {
for ( V_11 = 0 ; V_11 < V_72 ; V_11 ++ )
if ( * V_31 == V_73 [ V_11 ] . V_15 )
break;
if ( V_11 != V_72 ) {
V_9 += sprintf ( V_9 , L_73 , V_73 [ V_11 ] . V_19 ) ;
V_9 += V_73 [ V_11 ] . F_26 ( V_9 , V_31 ) ;
} else
V_9 += sprintf ( V_9 , L_78 , * V_31 , V_31 [ 1 ] ) ;
} else
V_9 += sprintf ( V_9 , L_75 , V_46 , * V_31 , V_31 [ 1 ] ) ;
if ( V_48 == 8 ) {
V_46 = V_47 ;
V_47 = 0 ;
V_48 = 0 ;
}
V_31 += V_31 [ 1 ] + 2 ;
}
} else if ( ( V_31 [ 0 ] == 8 ) && ( V_30 -> V_64 == V_74 ) ) {
V_31 ++ ;
V_40 = * V_31 ++ ;
if ( V_40 )
V_41 = * V_31 ++ ;
else
V_41 = 0 ;
V_42 = * V_31 ++ ;
for ( V_11 = 0 ; V_11 < V_66 ; V_11 ++ )
if ( V_67 [ V_11 ] . V_15 == V_42 )
break;
if ( V_11 == V_66 )
V_9 += sprintf ( V_9 , L_76 ,
V_41 & 0x7f , ( V_41 & 0x80 ) ? L_64 : L_65 ,
V_32 , V_42 ) ;
else
V_9 += sprintf ( V_9 , L_66 ,
V_41 & 0x7f , ( V_41 & 0x80 ) ? L_64 : L_65 ,
V_32 , V_67 [ V_11 ] . V_19 ) ;
while ( V_31 < V_38 ) {
if ( * V_31 & 0x80 ) {
switch ( ( * V_31 >> 4 ) & 7 ) {
case 1 :
V_9 += sprintf ( V_9 , L_68 , * V_31 & 0xf ) ;
break;
case 3 :
V_9 += sprintf ( V_9 , L_69 , * V_31 & 0xf ) ;
break;
case 5 :
V_9 += sprintf ( V_9 , L_79 , * V_31 & 0xf ) ;
break;
case 2 :
if ( * V_31 == 0xa0 ) {
V_9 += sprintf ( V_9 , L_70 ) ;
break;
}
if ( * V_31 == 0xa1 ) {
V_9 += sprintf ( V_9 , L_71 ) ;
}
break;
default:
V_9 += sprintf ( V_9 , L_72 , * V_31 ) ;
break;
}
V_31 ++ ;
continue;
}
for ( V_11 = 0 ; V_11 < V_75 ; V_11 ++ )
if ( * V_31 == V_76 [ V_11 ] . V_15 )
break;
if ( V_11 != V_75 ) {
V_9 += sprintf ( V_9 , L_73 , V_76 [ V_11 ] . V_19 ) ;
V_9 += V_76 [ V_11 ] . F_26 ( V_9 , V_31 ) ;
} else
V_9 += sprintf ( V_9 , L_78 , * V_31 , V_31 [ 1 ] ) ;
V_31 += V_31 [ 1 ] + 2 ;
}
} else {
V_9 += sprintf ( V_9 , L_80 , V_31 [ 0 ] ) ;
}
* V_9 = 0 ;
F_23 ( V_30 , NULL , V_30 -> V_33 ) ;
}
