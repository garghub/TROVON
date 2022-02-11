static int
F_1 ( struct V_1 * V_2 )
{
unsigned char * V_3 = V_2 -> V_4 ;
int V_5 ;
if ( V_2 -> V_6 -> V_7 & V_8 )
F_2 ( V_2 -> V_6 , L_1 , V_3 ) ;
if ( * V_3 == '-' ) {
V_3 ++ ;
if ( * V_3 ++ != 'c' )
return ( 0 ) ;
V_5 = 0 ;
while ( ( * V_3 <= '9' ) && ( * V_3 >= '0' ) )
V_5 = V_5 * 10 + * V_3 ++ - '0' ;
if ( V_5 > 65535 ) {
if ( V_2 -> V_6 -> V_7 & V_9 )
F_2 ( V_2 -> V_6 , L_2 , V_5 ) ;
return ( - V_10 ) ;
}
V_2 -> V_11 = V_5 & 0xFFFF ;
return ( 0 ) ;
}
if ( * V_3 == '*' ) {
if ( V_2 -> V_6 -> V_7 & V_12 )
F_2 ( V_2 -> V_6 , L_3 , V_2 -> V_11 , V_3 ) ;
return ( F_3 ( V_2 -> V_6 , V_2 -> V_4 + 1 ,
V_2 -> V_11 ) ) ;
}
return ( 0 ) ;
}
static T_1
F_4 ( struct V_13 * V_13 , const char T_2 * V_14 , T_3 V_15 , T_4 * V_16 )
{
struct V_1 * V_2 ;
int V_5 ;
unsigned char V_17 , * V_3 ;
if ( ! V_15 )
return ( 0 ) ;
if ( ! ( V_2 = V_13 -> V_18 ) )
return ( - V_19 ) ;
if ( V_2 -> V_20 == V_21 ) {
if ( F_5 ( & V_17 , V_14 , 1 ) )
return ( - V_19 ) ;
if ( V_17 == 0x1A ) {
if ( ( V_2 -> V_22 = F_6 ( V_2 -> V_6 , & V_2 -> V_23 ) ) <= 0 )
return ( V_2 -> V_22 ) ;
V_2 -> V_24 = 0 ;
V_2 -> V_20 = V_25 ;
} else {
V_2 -> V_24 = 0 ;
V_2 -> V_20 = V_26 ;
if ( V_2 -> V_6 -> V_20 != V_27 )
return ( - V_28 ) ;
V_2 -> V_4 [ V_29 - 1 ] = 0 ;
V_2 -> V_11 = 4098 ;
}
}
if ( V_2 -> V_20 == V_25 ) {
V_5 = V_2 -> V_22 - V_2 -> V_24 ;
if ( V_5 <= 0 )
return ( - V_30 ) ;
if ( V_5 < V_15 )
V_15 = V_5 ;
if ( F_5 ( V_2 -> V_23 + V_2 -> V_24 , V_14 , V_15 ) )
return ( - V_19 ) ;
V_2 -> V_24 += V_15 ;
if ( V_2 -> V_22 == V_2 -> V_24 ) {
V_2 -> V_22 = F_7 ( V_2 -> V_6 , V_2 -> V_24 ) ;
if ( V_2 -> V_22 <= 0 ) {
V_2 -> V_6 -> V_20 = V_31 ;
return ( V_2 -> V_22 ) ;
}
V_2 -> V_24 = 0 ;
}
}
else {
if ( V_2 -> V_6 -> V_20 != V_27 ) {
if ( V_2 -> V_6 -> V_7 & V_9 )
F_2 ( V_2 -> V_6 , L_4 ) ;
return ( - V_28 ) ;
}
V_5 = ( V_29 - 1 ) - V_2 -> V_24 ;
if ( V_5 > 0 ) {
if ( V_15 > V_5 )
V_15 = V_5 ;
if ( F_5 ( V_2 -> V_4 + V_2 -> V_24 , V_14 , V_15 ) )
return ( - V_19 ) ;
V_5 = V_15 ;
V_3 = V_2 -> V_4 + V_2 -> V_24 ;
while ( V_5 ) {
if ( ( * V_3 < ' ' ) && ( * V_3 != 9 ) )
break;
V_3 ++ ;
V_5 -- ;
}
if ( V_5 ) {
* V_3 ++ = 0 ;
V_15 -= ( V_5 - 1 ) ;
while ( ( V_5 ) && ( * V_3 < ' ' ) && ( * V_3 != 9 ) ) {
V_5 -- ;
V_15 ++ ;
V_3 ++ ;
}
V_2 -> V_24 = 0 ;
if ( ( V_5 = F_1 ( V_2 ) ) < 0 )
V_15 = V_5 ;
}
else {
V_2 -> V_24 += V_15 ;
if ( V_2 -> V_24 >= V_29 - 1 ) {
if ( V_2 -> V_6 -> V_7 & V_9 )
F_2 ( V_2 -> V_6 , L_5 , V_2 -> V_24 , V_15 ) ;
return ( - V_32 ) ;
}
}
}
else {
if ( V_2 -> V_6 -> V_7 & V_9 )
F_2 ( V_2 -> V_6 , L_6 ) ;
return ( - V_32 ) ;
}
}
return ( V_15 ) ;
}
static T_1
F_8 ( struct V_13 * V_13 , char T_2 * V_14 , T_3 V_15 , T_4 * V_16 )
{
char * V_3 ;
if ( ! ( V_13 -> V_33 & V_34 ) )
return - V_35 ;
if ( ! ( V_3 = V_13 -> V_18 ) )
return - V_19 ;
return F_9 ( V_14 , V_15 , V_16 , V_3 , strlen ( V_3 ) ) ;
}
static int
F_10 ( struct V_36 * V_37 , struct V_13 * V_38 )
{
T_5 * V_6 ;
struct V_1 * V_2 ;
char * V_3 , * V_39 ;
F_11 ( & V_40 ) ;
V_6 = F_12 ( V_37 ) ;
if ( V_6 -> V_7 & ( V_41 | V_42 ) )
F_2 ( V_6 , L_7 ,
V_38 -> V_43 -> V_44 , V_38 -> V_43 -> V_45 ,
V_38 -> V_33 ) ;
if ( ( V_38 -> V_33 & ( V_34 | V_46 ) ) == V_46 ) {
if ( ! ( V_2 = F_13 ( sizeof( struct V_1 ) , V_47 ) ) ) {
F_14 ( & V_40 ) ;
return ( - V_19 ) ;
}
V_2 -> V_6 = V_6 ;
V_2 -> V_24 = 0 ;
V_2 -> V_20 = V_21 ;
V_38 -> V_18 = V_2 ;
} else if ( ( V_38 -> V_33 & ( V_34 | V_46 ) ) == V_34 ) {
if ( ! ( V_39 = F_13 ( V_48 * 2 + 2 , V_47 ) ) ) {
F_14 ( & V_40 ) ;
return ( - V_19 ) ;
}
V_38 -> V_18 = V_39 ;
sprintf ( V_39 , L_8 ) ;
V_3 = V_39 ;
while ( * V_3 )
V_3 ++ ;
while ( ( ( V_3 - V_39 ) % ( V_48 + 1 ) ) != V_48 )
* V_3 ++ = ' ' ;
* V_3 ++ = '\n' ;
sprintf ( V_3 , L_9 ,
V_6 -> V_49 ,
V_6 -> V_50 ,
F_15 ( V_6 -> V_51 ) ,
V_6 -> V_52 ,
V_6 -> V_53 ,
V_6 -> V_54 ,
V_6 -> V_55 ,
V_6 -> V_56 ,
V_6 -> V_57 ,
V_6 -> V_20 ,
F_16 ( V_6 ) ) ;
while ( * V_3 )
V_3 ++ ;
while ( ( ( V_3 - V_39 ) % ( V_48 + 1 ) ) != V_48 )
* V_3 ++ = ' ' ;
* V_3 ++ = '\n' ;
* V_3 = 0 ;
} else {
F_14 ( & V_40 ) ;
return ( - V_35 ) ;
}
F_14 ( & V_40 ) ;
return F_17 ( V_37 , V_38 ) ;
}
static int
F_18 ( struct V_36 * V_37 , struct V_13 * V_38 )
{
T_5 * V_6 ;
struct V_1 * V_2 ;
int V_58 = 0 ;
F_11 ( & V_40 ) ;
V_6 = F_12 ( V_37 ) ;
if ( V_6 -> V_7 & ( V_41 | V_42 ) )
F_2 ( V_6 , L_10 ,
V_38 -> V_43 -> V_44 , V_38 -> V_43 -> V_45 ,
V_38 -> V_33 ) ;
if ( ( V_38 -> V_33 & ( V_34 | V_46 ) ) == V_46 ) {
if ( V_38 -> V_18 ) {
V_2 = V_38 -> V_18 ;
if ( V_2 -> V_20 == V_25 )
V_58 = F_19 ( V_2 -> V_6 ) ;
F_20 ( V_38 -> V_18 ) ;
}
} else if ( ( V_38 -> V_33 & ( V_34 | V_46 ) ) == V_34 ) {
F_20 ( V_38 -> V_18 ) ;
}
F_14 ( & V_40 ) ;
return ( V_58 ) ;
}
int
F_21 ( void )
{
T_5 * V_6 ;
unsigned char V_59 [ 20 ] ;
V_60 = F_22 ( V_61 , V_62 . V_63 ) ;
if ( ! V_60 ) {
F_23 ( V_64 L_11 ) ;
return ( - 1 ) ;
}
V_6 = V_65 ;
while ( V_6 ) {
sprintf ( V_59 , L_12 , V_66 , V_6 -> V_49 ) ;
if ( ( V_6 -> V_67 = ( void * ) F_24 ( V_59 ,
V_68 | V_69 | V_70 ,
V_60 ,
& V_71 ,
V_6 ) ) != NULL ) {
F_25 ( V_6 ) ;
}
V_6 = V_6 -> V_72 ;
}
F_23 ( V_73 L_13 ) ;
return ( 0 ) ;
}
void
F_26 ( void )
{
T_5 * V_6 ;
unsigned char V_59 [ 20 ] ;
V_6 = V_65 ;
while ( V_6 ) {
sprintf ( V_59 , L_12 , V_66 , V_6 -> V_49 ) ;
if ( V_6 -> V_67 )
F_27 ( V_59 , V_60 ) ;
F_28 ( V_6 ) ;
V_6 = V_6 -> V_72 ;
}
F_27 ( V_61 , V_62 . V_63 ) ;
}
