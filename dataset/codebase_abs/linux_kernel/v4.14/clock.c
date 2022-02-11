static void F_1 ( int V_1 , int V_2 , int * V_3 ,
int * V_4 , int * V_5 )
{
int V_6 , V_7 , V_8 , V_9 , V_10 = V_2 ;
for ( V_6 = 1 ; V_6 <= 16 ; V_6 ++ )
for ( V_7 = 1 ; V_7 <= 32 ; V_7 ++ )
for ( V_8 = 1 ; V_8 <= 32 ; V_8 ++ ) {
V_9 = abs ( V_1 / V_7 * V_6 / V_8 - V_2 ) ;
if ( V_9 < V_10 ) {
V_10 = V_9 ;
* V_5 = V_6 ;
* V_3 = V_7 ;
* V_4 = V_8 ;
}
}
}
static void F_2 ( int V_1 , int V_2 , int * V_3 , int * V_4 ,
int * V_5 )
{
int V_11 , V_12 , V_13 ;
for ( * V_3 = 1 ; * V_3 <= 32 ; ( * V_3 ) ++ ) {
V_12 = V_1 / * V_3 ;
V_11 = F_3 ( V_2 , V_12 ) ;
* V_5 = V_2 / V_11 ;
* V_4 = V_12 / V_11 ;
if ( ( * V_5 < 1 ) || ( * V_5 >= 16 ) )
continue;
if ( ( * V_4 > 0 ) & ( * V_4 <= 32 ) )
break;
}
if ( V_1 / * V_3 * * V_5 / * V_4 != V_2 ) {
F_1 ( V_1 , V_2 , V_3 , V_4 , V_5 ) ;
V_13 = V_1 / * V_3 * * V_5 / * V_4 ;
F_4 ( V_14
L_1 ,
V_2 , V_13 ) ;
}
F_4 ( V_15 L_2 ,
* V_3 , * V_4 , * V_5 ) ;
}
static int F_5 ( void )
{
T_1 V_16 , V_17 ;
T_2 V_18 = F_6 () ;
V_16 = F_7 ( ( void * ) F_8 ( V_19 + 0x18 ) ) ;
V_17 = F_7 ( ( void * ) F_8 ( V_19 + 0x1c ) ) ;
if ( V_17 & ( 1 << 23 ) )
return 0 ;
if ( ( V_18 >= 0x23 ) && ( V_18 != 0x57 ) )
return 250000000 ;
if ( ( ( ( V_17 & 0x1fff ) << 10 ) | ( ( V_16 & 0xffc00000 ) >> 22 ) )
> 4208000 )
return 250000000 ;
return 0 ;
}
static int F_9 ( T_1 V_20 , struct V_21 * clock ,
T_1 * V_22 , T_1 V_23 )
{
int V_24 ;
int V_25 = V_26 ;
T_1 V_27 = F_7 ( & clock -> V_27 ) ;
T_1 V_28 = F_7 ( & clock -> V_28 ) ;
int V_3 = ( ( V_27 & V_29 ) >> V_30 ) + 1 ;
int V_4 = ( V_27 & V_31 ) + 1 ;
int V_32 = V_3 * V_4 ;
int V_5 = ( ( V_28 & V_33 ) >> V_34 ) + 1 ;
switch ( ( * V_22 & ( V_35 << V_20 ) ) >> V_20 ) {
case V_36 :
V_25 = V_23 ;
break;
case V_37 :
V_25 = V_26 ;
break;
case V_38 :
V_25 = V_39 ;
break;
case V_40 :
V_25 = V_41 . V_42 ;
break;
}
if ( * V_22 & V_43 )
return V_25 / V_32 ;
if ( ( V_28 & V_44 ) == 0 )
return ( V_25 >> ( V_5 / 16 + 1 ) ) / V_32 ;
if ( ( V_28 & ( V_45 | V_46 ) ) == ( V_45 | V_46 ) ) {
V_24 = ( V_5 & 1 ) ?
( V_25 * V_5 ) >> 1 :
( V_25 * ( V_5 - 1 ) ) >> 2 ;
return V_24 / V_32 ;
}
if ( V_5 == 16 )
return V_25 / V_32 ;
return V_25 * V_5 / V_32 ;
}
static void F_10 ( T_1 V_20 , struct V_21 * clock ,
T_1 * V_22 , T_1 V_47 )
{
int V_3 , V_4 , V_5 ;
int V_25 = V_48 . V_42 ;
switch ( ( * V_22 & ( V_35 << V_20 ) ) >> V_20 ) {
case V_36 :
V_25 = V_48 . V_42 ;
break;
case V_37 :
V_25 = V_26 ;
break;
case V_38 :
V_25 = V_39 ;
break;
case V_40 :
V_25 = V_41 . V_42 ;
break;
}
F_2 ( V_25 , V_47 , & V_3 , & V_4 , & V_5 ) ;
F_11 ( ( ( V_3 - 1 ) << V_30 ) | ( V_4 - 1 ) , & clock -> V_27 ) ;
F_12 ( 1 ) ;
F_11 ( 4 , & clock -> V_28 ) ;
while ( F_7 ( & clock -> V_28 ) & V_49 )
;
F_11 ( ( ( V_5 - 1 ) << V_34 ) | ( 0xff << 3 ) | 0x0e , & clock -> V_28 ) ;
F_12 ( 75 ) ;
}
static void T_3 F_13 ( void )
{
T_1 * V_22 = ( T_1 * ) F_14 ( V_50 , 4 ) ;
struct V_51 * V_52 =
F_14 ( V_53 ,
sizeof( struct V_51 ) ) ;
V_48 . V_42 = F_9 ( V_54 ,
& V_52 -> V_55 , V_22 , V_56 ) ;
if ( * V_22 & V_57 )
V_41 . V_42 = F_9 ( V_58 ,
& V_52 -> V_59 , V_22 , V_56 ) ;
else
V_41 . V_42 = V_48 . V_42 ;
if ( V_60 . V_42 == 250000000 )
F_10 ( V_61 , & V_52 -> V_62 ,
V_22 , V_60 . V_42 ) ;
F_15 ( V_52 ) ;
F_15 ( V_22 ) ;
}
static void F_16 ( int V_1 , struct V_63 * clock ,
int V_3 , int V_4 , int V_64 , int V_5 , T_1 V_47 )
{
F_4 ( V_65
L_3
L_4 ,
V_1 , V_47 , V_3 , V_4 , V_64 , V_5 ) ;
F_11 ( 0 , & clock -> V_27 ) ;
F_11 ( V_66 | ( ( V_3 - 1 ) & 0x1F ) , & clock -> V_3 ) ;
F_11 ( ( V_5 - 1 ) & 0xF , & clock -> V_5 ) ;
while ( F_7 ( & clock -> V_67 ) & 0x1 )
;
F_11 ( V_66 | ( ( V_4 - 1 ) & 0x1F ) , & clock -> V_4 ) ;
F_11 ( F_7 ( & clock -> V_68 ) | 1 , & clock -> V_68 ) ;
F_11 ( F_7 ( & clock -> V_69 ) | 1 , & clock -> V_69 ) ;
while ( F_7 ( & clock -> V_67 ) & 0x1 )
;
F_11 ( V_66 | ( ( V_64 - 1 ) & 0x1F ) , & clock -> V_64 ) ;
F_11 ( F_7 ( & clock -> V_68 ) | 1 , & clock -> V_68 ) ;
F_11 ( F_7 ( & clock -> V_69 ) | 1 , & clock -> V_69 ) ;
while ( F_7 ( & clock -> V_67 ) & 0x1 )
;
F_11 ( F_7 ( & clock -> V_27 ) | 1 , & clock -> V_27 ) ;
}
static int F_17 ( int V_70 , T_1 * V_22 )
{
if ( * V_22 & V_57 )
switch ( V_70 ) {
case V_71 :
return V_26 ;
default:
return V_56 ;
}
else
if ( * V_22 & V_72 )
switch ( V_70 ) {
case V_71 :
return V_26 ;
default:
return V_56 ;
}
else
return V_26 ;
}
static void T_3 F_18 ( void )
{
T_1 * V_22 = ( T_1 * ) F_14 ( V_50 , 4 ) ;
struct V_73 * V_52 =
F_14 ( V_74 ,
sizeof( struct V_73 ) ) ;
int V_75 , V_76 , V_77 , V_78 ;
int V_79 , V_80 , V_81 , V_82 ;
int V_83 , V_84 , V_85 , V_86 ;
V_75 = F_17 ( V_87 , V_22 ) ;
V_79 = F_17 ( V_71 , V_22 ) ;
if ( * V_22 & V_57 ) {
F_4 ( V_65 L_5 ) ;
F_4 ( V_65 L_6 ) ;
F_2 ( V_79 , V_88 ,
& V_81 , & V_82 , & V_80 ) ;
V_48 . V_42 =
( ( V_79 / V_81 ) * V_80 ) / V_82 ;
F_16 ( V_79 , & V_52 -> V_62 ,
V_81 , V_82 * 2 , V_82 , V_80 * 2 ,
V_48 . V_42 ) ;
F_4 ( V_65 L_7 ) ;
F_2 ( V_75 , V_89 , & V_77 ,
& V_78 , & V_76 ) ;
V_41 . V_42 =
( ( V_75 / V_77 ) * V_76 ) / V_78 ;
F_16 ( V_75 , & V_52 -> V_59 ,
V_77 , V_78 , - 1 , V_76 ,
V_41 . V_42 ) ;
} else
if ( * V_22 & V_72 ) {
F_4 ( V_65 L_8 ) ;
F_4 ( V_65 L_7 ) ;
F_2 ( V_75 , V_89 , & V_77 ,
& V_78 , & V_76 ) ;
V_41 . V_42 = ( ( V_75 / V_77 ) * V_76 )
/ V_78 ;
F_16 ( V_75 , & V_52 -> V_59 ,
V_77 , V_78 , - 1 , V_76 ,
V_41 . V_42 ) ;
F_4 ( V_65 L_6 ) ;
F_2 ( V_79 , V_88 , & V_81 ,
& V_82 , & V_80 ) ;
V_48 . V_42 = V_41 . V_42 / 2 ;
F_16 ( V_79 , & V_52 -> V_62 ,
V_81 , V_82 * 2 , V_82 ,
V_80 * 2 , V_48 . V_42 ) ;
} else {
F_4 ( V_65 L_9 ) ;
F_4 ( V_65 L_6 ) ;
F_2 ( V_79 , V_88 , & V_81 ,
& V_82 , & V_80 ) ;
V_48 . V_42 = ( ( V_79 / V_81 ) * V_80 )
/ V_82 ;
F_16 ( V_79 , & V_52 -> V_62 ,
V_81 , V_82 * 2 , V_82 ,
V_80 * 2 , V_48 . V_42 ) ;
V_41 . V_42 = V_48 . V_42 ;
}
F_4 ( V_65 L_10 ) ;
V_83 = V_48 . V_42 ;
F_2 ( V_83 , V_90 , & V_85 ,
& V_86 , & V_84 ) ;
F_16 ( V_83 , & V_52 -> V_91 ,
V_85 , V_86 , - 1 , V_84 ,
V_90 ) ;
V_60 . V_42 = V_41 . V_42 ;
F_15 ( V_52 ) ;
F_15 ( V_22 ) ;
}
int F_19 ( struct V_92 * V_92 )
{
return 0 ;
}
void F_20 ( struct V_92 * V_92 )
{
}
unsigned long F_21 ( struct V_92 * V_92 )
{
if ( ! V_92 )
return 0 ;
return V_92 -> V_42 ;
}
struct V_92 * F_22 ( struct V_93 * V_94 , const char * V_95 )
{
if ( ! strcmp ( V_95 , L_11 ) )
return & V_48 ;
if ( ! strcmp ( V_95 , L_12 ) )
return & V_96 ;
if ( ! strcmp ( V_95 , L_13 ) )
return & V_41 ;
if ( ! strcmp ( V_95 , L_14 ) )
return & V_60 ;
if ( ! strcmp ( V_95 , L_15 ) )
return & V_96 ;
return F_23 ( - V_97 ) ;
}
void F_24 ( struct V_92 * V_92 )
{
}
void T_3 F_25 ( void )
{
switch ( F_26 () ) {
case V_98 :
case V_99 :
F_18 () ;
break;
case V_100 :
V_60 . V_42 = F_5 () ;
F_13 () ;
break;
default:
break;
}
V_96 . V_42 = V_48 . V_42 / 2 ;
}
