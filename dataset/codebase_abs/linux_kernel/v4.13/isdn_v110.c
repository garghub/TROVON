static inline unsigned char
F_1 ( unsigned char V_1 , int V_2 )
{
unsigned char V_3 = V_1 ;
unsigned char V_4 = 128 ;
int V_5 ;
int V_6 ;
int V_7 = ( 8 / V_2 ) ;
V_1 = 0 ;
for ( V_5 = 0 ; V_5 < V_7 ; V_5 ++ ) {
for ( V_6 = 0 ; V_6 < V_2 ; V_6 ++ ) {
if ( V_3 & ( V_4 >> V_6 ) )
V_1 |= V_4 >> ( V_2 - V_6 - 1 ) ;
}
V_4 >>= V_2 ;
}
return V_1 ;
}
static T_1 *
F_2 ( unsigned char V_8 , int V_9 , int V_10 )
{
int V_5 ;
T_1 * V_11 ;
if ( ( V_11 = F_3 ( sizeof( T_1 ) , V_12 ) ) == NULL )
return NULL ;
V_11 -> V_8 = V_8 ;
V_11 -> V_13 = 0 ;
for ( V_5 = 0 ; V_8 & ( 1 << V_5 ) ; V_5 ++ )
V_11 -> V_13 ++ ;
V_11 -> V_14 = 8 / V_11 -> V_13 ;
V_11 -> V_15 = 0 ;
switch ( V_8 ) {
case V_16 :
V_11 -> V_17 = V_18 ;
V_11 -> V_19 = V_20 ;
break;
case V_21 :
V_11 -> V_17 = V_22 ;
V_11 -> V_19 = V_23 ;
break;
default:
V_11 -> V_17 = V_24 ;
V_11 -> V_19 = V_25 ;
break;
}
V_11 -> V_26 = V_11 -> V_14 * 10 ;
V_11 -> V_27 = 5 ;
V_11 -> V_28 = 0 ;
V_11 -> V_29 = 1 ;
V_11 -> V_3 = 0 ;
V_11 -> V_30 = V_9 ;
V_11 -> V_10 = V_10 - V_9 ;
if ( ( V_11 -> V_31 = F_4 ( V_10 , V_12 ) ) == NULL ) {
F_5 ( V_11 ) ;
return NULL ;
}
return V_11 ;
}
void
F_6 ( T_1 * V_11 )
{
if ( V_11 == NULL )
return;
#ifdef F_7
F_8 ( V_32 L_1 ) ;
#endif
F_5 ( V_11 -> V_31 ) ;
F_5 ( V_11 ) ;
}
static int
F_9 ( T_1 * V_11 )
{
int V_5 ;
for ( V_5 = 0 ; ( V_5 < V_11 -> V_15 ) && ( V_5 < V_11 -> V_14 ) ; V_5 ++ )
if ( ( V_11 -> V_33 [ V_5 ] & V_11 -> V_8 ) != 0 )
break;
return V_5 ;
}
static void
F_10 ( T_1 * V_11 )
{
unsigned char * V_34 = V_11 -> V_33 ;
int V_35 = V_11 -> V_15 ;
if ( V_35 == 0 )
return;
for ( V_34 ++ , V_35 -- ; V_35 > 0 ; V_35 -- , V_34 ++ )
if ( ( * V_34 & V_11 -> V_8 ) == 0 )
break;
if ( V_35 )
memcpy ( V_11 -> V_33 , V_34 , V_35 ) ;
V_11 -> V_15 = V_35 ;
#ifdef F_7
F_8 ( V_32 L_2 ) ;
#endif
}
static int
F_11 ( T_1 * V_11 , unsigned char * V_36 , int V_35 , unsigned char * V_37 )
{
int line = 0 ;
int V_38 = 0 ;
int V_39 = 64 ;
int V_28 = V_11 -> V_28 ;
int V_29 = V_11 -> V_29 ;
unsigned char V_3 = V_11 -> V_3 ;
while ( line < V_35 ) {
if ( ( line % 10 ) == 0 ) {
if ( V_36 [ line ] != 0x00 ) {
#ifdef F_7
F_8 ( V_32 L_3 ) ;
#endif
}
line ++ ;
continue;
} else if ( ( line % 10 ) == 5 ) {
if ( ( V_36 [ line ] & 0x70 ) != 0x30 ) {
#ifdef F_7
F_8 ( V_32 L_4 ) ;
#endif
}
line ++ ;
continue;
} else if ( ! V_28 ) {
V_28 = ( V_36 [ line ] & V_39 ) ? 0 : 1 ;
V_40:
if ( V_39 > 2 ) {
V_39 >>= 1 ;
continue;
}
V_39 = 64 ;
line ++ ;
continue;
} else {
if ( V_36 [ line ] & V_39 )
V_3 |= V_29 ;
else
V_3 &= V_29 - 1 ;
if ( V_29 < 128 )
V_29 <<= 1 ;
else {
V_37 [ V_38 ++ ] = V_3 ;
V_28 = V_3 = 0 ;
V_29 = 1 ;
}
goto V_40;
}
}
V_11 -> V_28 = V_28 ;
V_11 -> V_29 = V_29 ;
V_11 -> V_3 = V_3 ;
return V_38 ;
}
struct V_41 *
F_12 ( T_1 * V_11 , struct V_41 * V_42 )
{
int V_5 ;
int V_6 ;
int V_35 ;
unsigned char * V_43 ;
unsigned char * V_34 ;
if ( ! V_42 ) {
F_8 ( V_44 L_5 ) ;
return NULL ;
}
V_34 = V_42 -> V_45 ;
V_35 = V_42 -> V_35 ;
if ( V_11 == NULL ) {
F_8 ( V_44 L_6 ) ;
F_13 ( V_42 ) ;
return NULL ;
}
if ( V_11 -> V_15 == 0 )
for (; V_35 > 0 ; V_35 -- , V_34 ++ )
if ( ( * V_34 & V_11 -> V_8 ) == 0 )
break;
if ( V_35 == 0 ) {
F_13 ( V_42 ) ;
return NULL ;
}
memcpy ( & ( V_11 -> V_33 [ V_11 -> V_15 ] ) , V_34 , V_35 ) ;
V_11 -> V_15 += V_35 ;
V_46:
if ( V_11 -> V_15 < V_11 -> V_14 ) {
F_13 ( V_42 ) ;
return NULL ;
}
if ( F_9 ( V_11 ) != V_11 -> V_14 ) {
F_10 ( V_11 ) ;
goto V_46;
}
V_35 = ( V_11 -> V_15 - ( V_11 -> V_15 % ( 10 * V_11 -> V_14 ) ) ) / V_11 -> V_14 ;
if ( ( V_43 = F_4 ( V_35 , V_12 ) ) == NULL ) {
F_8 ( V_44 L_7 ) ;
F_13 ( V_42 ) ;
return NULL ;
}
for ( V_5 = 0 ; V_5 < V_35 ; V_5 ++ ) {
V_43 [ V_5 ] = 0 ;
for ( V_6 = 0 ; V_6 < V_11 -> V_14 ; V_6 ++ )
V_43 [ V_5 ] |= ( V_11 -> V_33 [ ( V_5 * V_11 -> V_14 ) + V_6 ] & V_11 -> V_8 ) << ( 8 - ( ( V_6 + 1 ) * V_11 -> V_13 ) ) ;
V_43 [ V_5 ] = F_1 ( V_43 [ V_5 ] , V_11 -> V_13 ) ;
}
V_11 -> V_15 = ( V_11 -> V_15 % ( 10 * V_11 -> V_14 ) ) ;
memcpy ( V_11 -> V_33 , & ( V_11 -> V_33 [ V_35 * V_11 -> V_14 ] ) , V_11 -> V_15 ) ;
F_14 ( V_42 , F_11 ( V_11 , V_43 , V_35 , V_42 -> V_45 ) ) ;
F_5 ( V_43 ) ;
if ( V_42 -> V_35 )
return V_42 ;
else {
F_15 ( V_42 ) ;
return NULL ;
}
}
static int
F_16 ( unsigned char * V_37 , int V_35 , unsigned char * V_36 , int V_47 )
{
int line = 0 ;
int V_5 = 0 ;
int V_39 = 128 ;
int V_29 = 1 ;
int V_28 = 3 ;
int V_48 [] = { 0 , 1 , 1 } ;
while ( ( V_5 < V_35 ) && ( line < V_47 ) ) {
switch ( line % 10 ) {
case 0 :
V_36 [ line ++ ] = 0x00 ;
V_39 = 128 ;
break;
case 5 :
V_36 [ line ++ ] = 0xbf ;
V_39 = 128 ;
break;
}
if ( line >= V_47 ) {
F_8 ( V_44 L_8 ) ;
return line ;
}
V_49:
switch ( V_39 ) {
case 1 :
line ++ ;
if ( line >= V_47 ) {
F_8 ( V_44 L_8 ) ;
return line ;
}
case 128 :
V_36 [ line ] = 128 ;
V_39 = 64 ;
continue;
}
if ( V_28 ) {
V_28 -- ;
V_36 [ line ] |= V_48 [ V_28 ] ? V_39 : 0 ;
V_39 >>= 1 ;
goto V_49;
}
V_36 [ line ] |= ( V_37 [ V_5 ] & V_29 ) ? V_39 : 0 ;
if ( V_29 == 128 ) {
V_29 = 1 ;
V_5 ++ ;
if ( V_5 < V_35 )
V_28 = 3 ;
else {
V_36 [ line ] |= ( V_39 - 1 ) & 0xfe ;
break;
}
} else
V_29 <<= 1 ;
V_39 >>= 1 ;
goto V_49;
}
if ( ( line ) && ( ( line + 10 ) < V_47 ) )
switch ( ++ line % 10 ) {
case 1 :
V_36 [ line ++ ] = 0xfe ;
case 2 :
V_36 [ line ++ ] = 0xfe ;
case 3 :
V_36 [ line ++ ] = 0xfe ;
case 4 :
V_36 [ line ++ ] = 0xfe ;
case 5 :
V_36 [ line ++ ] = 0xbf ;
case 6 :
V_36 [ line ++ ] = 0xfe ;
case 7 :
V_36 [ line ++ ] = 0xfe ;
case 8 :
V_36 [ line ++ ] = 0xfe ;
case 9 :
V_36 [ line ++ ] = 0xfe ;
}
return line ;
}
static struct V_41 *
F_17 ( T_1 * V_11 )
{
struct V_41 * V_42 ;
if ( V_11 == NULL ) {
F_8 ( V_44 L_9 ) ;
return NULL ;
}
if ( ( V_42 = F_18 ( V_11 -> V_26 + V_11 -> V_30 ) ) ) {
F_19 ( V_42 , V_11 -> V_30 ) ;
F_20 ( V_42 , V_11 -> V_19 , V_11 -> V_26 ) ;
}
return V_42 ;
}
static struct V_41 *
F_21 ( T_1 * V_11 )
{
struct V_41 * V_42 ;
if ( V_11 == NULL ) {
F_8 ( V_44 L_9 ) ;
return NULL ;
}
if ( ( V_42 = F_18 ( V_11 -> V_26 + V_11 -> V_30 ) ) ) {
F_19 ( V_42 , V_11 -> V_30 ) ;
F_20 ( V_42 , V_11 -> V_17 , V_11 -> V_26 ) ;
}
return V_42 ;
}
struct V_41 *
F_22 ( T_1 * V_11 , struct V_41 * V_42 )
{
int V_5 ;
int V_6 ;
int V_50 ;
int V_47 ;
int V_51 ;
int V_52 ;
int V_53 ;
int V_54 ;
int V_55 ;
unsigned char * V_56 ;
unsigned char * V_34 ;
struct V_41 * V_57 ;
if ( V_11 == NULL ) {
F_8 ( V_44 L_10 ) ;
return NULL ;
}
if ( ! V_42 ) {
F_8 ( V_44 L_11 ) ;
return NULL ;
}
V_50 = V_42 -> V_35 ;
V_55 = ( V_50 + 3 ) / 4 ;
V_56 = V_11 -> V_31 ;
if ( ( V_55 * 40 ) > V_11 -> V_10 ) {
V_52 = V_11 -> V_10 ;
V_50 = V_11 -> V_10 / 40 ;
} else
V_52 = V_55 * 40 ;
if ( ! ( V_57 = F_18 ( V_52 + V_11 -> V_30 + sizeof( int ) ) ) ) {
F_8 ( V_44 L_12 ) ;
return NULL ;
}
F_19 ( V_57 , V_11 -> V_30 + sizeof( int ) ) ;
if ( V_42 -> V_35 == 0 ) {
F_20 ( V_57 , V_11 -> V_17 , V_11 -> V_26 ) ;
* ( ( int * ) F_23 ( V_57 , sizeof( int ) ) ) = 0 ;
return V_57 ;
}
V_47 = F_16 ( V_42 -> V_45 , V_50 , V_56 , V_52 ) ;
V_34 = F_24 ( V_57 , V_52 ) ;
V_51 = 0 ;
V_53 = 8 - V_11 -> V_13 ;
V_54 = V_11 -> V_8 << V_53 ;
for ( V_5 = 0 ; V_5 < V_47 ; V_5 ++ ) {
V_56 [ V_5 ] = F_1 ( V_56 [ V_5 ] , V_11 -> V_13 ) ;
for ( V_6 = 0 ; V_6 < V_11 -> V_14 ; V_6 ++ ) {
if ( V_52 -- )
* V_34 ++ = ~ V_11 -> V_8 | ( ( ( V_56 [ V_5 ] << ( V_6 * V_11 -> V_13 ) ) & V_54 ) >> V_53 ) ;
else {
F_8 ( V_44 L_13 ) ;
goto V_58;
}
V_51 ++ ;
}
}
V_58:
F_14 ( V_57 , V_51 ) ;
* ( ( int * ) F_23 ( V_57 , sizeof( int ) ) ) = V_50 ;
return V_57 ;
}
int
F_25 ( int V_59 , T_2 * V_1 )
{
T_1 * V_11 = NULL ;
int V_5 ;
int V_60 = 0 ;
if ( V_59 < 0 )
return 0 ;
switch ( V_1 -> V_61 ) {
case V_62 :
if ( ! ( V_11 = V_63 -> V_64 [ V_59 ] ) )
return 0 ;
F_26 ( & V_63 -> V_65 [ V_59 ] ) ;
for ( V_5 = 0 ; V_5 * V_11 -> V_26 < V_1 -> V_66 . V_67 ; V_5 ++ ) {
if ( V_11 -> V_68 > 0 ) {
V_11 -> V_68 -- ;
V_60 = 1 ;
} else {
if ( V_11 -> V_69 > 0 )
V_11 -> V_69 -- ;
V_60 = 0 ;
}
}
for ( V_5 = V_11 -> V_69 + V_11 -> V_68 ; V_5 < 2 ; V_5 ++ ) {
struct V_41 * V_42 ;
if ( V_11 -> V_27 > 0 )
V_42 = F_17 ( V_11 ) ;
else
V_42 = F_21 ( V_11 ) ;
if ( V_42 ) {
if ( V_63 -> V_70 [ V_1 -> V_71 ] -> V_72 -> V_73 ( V_1 -> V_71 , V_1 -> V_74 , 1 , V_42 ) <= 0 ) {
F_13 ( V_42 ) ;
break;
} else {
if ( V_11 -> V_27 )
V_11 -> V_27 -- ;
V_11 -> V_68 ++ ;
}
} else
break;
}
F_27 ( & V_63 -> V_65 [ V_59 ] ) ;
return V_60 ;
case V_75 :
case V_76 :
while ( 1 ) {
F_26 ( & V_63 -> V_65 [ V_59 ] ) ;
if ( F_28 ( & V_63 -> V_65 [ V_59 ] ) ) {
F_6 ( V_63 -> V_64 [ V_59 ] ) ;
V_63 -> V_64 [ V_59 ] = NULL ;
break;
}
F_29 ( 1 ) ;
}
break;
case V_77 :
if ( V_63 -> V_78 [ V_59 ] && ( V_63 -> V_64 [ V_59 ] == NULL ) ) {
int V_9 = V_63 -> V_70 [ V_1 -> V_71 ] -> V_72 -> V_79 ;
int V_10 = V_63 -> V_70 [ V_1 -> V_71 ] -> V_72 -> V_80 ;
F_26 ( & V_63 -> V_65 [ V_59 ] ) ;
switch ( V_63 -> V_78 [ V_59 ] ) {
case V_81 :
V_63 -> V_64 [ V_59 ] = F_2 ( V_82 , V_9 , V_10 ) ;
break;
case V_83 :
V_63 -> V_64 [ V_59 ] = F_2 ( V_21 , V_9 , V_10 ) ;
break;
case V_84 :
V_63 -> V_64 [ V_59 ] = F_2 ( V_16 , V_9 , V_10 ) ;
break;
default: ;
}
if ( ( V_11 = V_63 -> V_64 [ V_59 ] ) ) {
while ( V_11 -> V_27 ) {
struct V_41 * V_42 = F_17 ( V_11 ) ;
if ( V_63 -> V_70 [ V_1 -> V_71 ] -> V_72 -> V_73 ( V_1 -> V_71 , V_1 -> V_74 , 1 , V_42 ) <= 0 ) {
F_13 ( V_42 ) ;
break;
}
V_11 -> V_27 -- ;
V_11 -> V_68 ++ ;
}
} else
F_8 ( V_44 L_14 , V_59 ) ;
F_27 ( & V_63 -> V_65 [ V_59 ] ) ;
}
break;
default:
return 0 ;
}
return 0 ;
}
