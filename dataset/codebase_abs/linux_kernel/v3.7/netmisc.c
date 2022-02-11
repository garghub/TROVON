static int
F_1 ( const int V_1 , const char * V_2 , int V_3 , void * V_4 )
{
int V_5 = 0 ;
if ( V_1 == V_6 )
V_5 = F_2 ( V_2 , V_3 , V_4 , '\\' , NULL ) ;
else if ( V_1 == V_7 )
V_5 = F_3 ( V_2 , V_3 , V_4 , '\\' , NULL ) ;
F_4 ( V_8 , L_1 ,
V_5 , V_3 , V_3 , V_2 ) ;
if ( V_5 > 0 )
V_5 = 1 ;
return V_5 ;
}
int
F_5 ( struct V_9 * V_4 , const char * V_10 , int V_3 )
{
int V_11 , V_12 , V_13 ;
const char * V_14 ;
char V_15 [ 13 ] ;
struct V_16 * V_17 = (struct V_16 * ) V_4 ;
struct V_18 * V_19 = (struct V_18 * ) V_4 ;
if ( F_1 ( V_6 , V_10 , V_3 , & V_17 -> V_20 . V_21 ) ) {
V_17 -> V_22 = V_6 ;
return 1 ;
}
V_14 = memchr ( V_10 , '%' , V_3 ) ;
V_12 = V_14 ? V_14 - V_10 : V_3 ;
V_11 = F_1 ( V_7 , V_10 , V_12 , & V_19 -> V_23 . V_24 ) ;
if ( ! V_11 )
return V_11 ;
V_19 -> V_25 = V_7 ;
if ( V_14 ) {
V_13 = V_3 - ( V_12 + 1 ) ;
if ( V_13 <= 0 || V_13 > 12 )
return 0 ;
memcpy ( V_15 , V_14 + 1 , V_13 ) ;
V_15 [ V_13 ] = '\0' ;
V_11 = F_6 ( V_15 , 0 , & V_19 -> V_26 ) ;
V_11 = ( V_11 == 0 ) ? 1 : 0 ;
}
return V_11 ;
}
int
F_7 ( struct V_9 * V_27 , const unsigned short int V_28 )
{
switch ( V_27 -> V_29 ) {
case V_6 :
( (struct V_16 * ) V_27 ) -> V_30 = F_8 ( V_28 ) ;
break;
case V_7 :
( (struct V_18 * ) V_27 ) -> V_31 = F_8 ( V_28 ) ;
break;
default:
return 0 ;
}
return 1 ;
}
int
F_9 ( struct V_9 * V_4 , const char * V_10 , int V_3 ,
const unsigned short int V_28 )
{
if ( ! F_5 ( V_4 , V_10 , V_3 ) )
return 0 ;
return F_7 ( V_4 , V_28 ) ;
}
static void
F_10 ( T_1 V_32 )
{
int V_33 = 0 ;
while ( V_34 [ V_33 ] . V_35 != NULL ) {
if ( ( ( V_34 [ V_33 ] . V_36 ) & 0xFFFFFF ) ==
( V_32 & 0xFFFFFF ) ) {
F_11 ( V_37 L_2 ,
V_32 , V_34 [ V_33 ] . V_35 ) ;
}
V_33 ++ ;
}
return;
}
static void
F_12 ( T_1 V_38 , T_2 * V_39 , T_3 * V_40 )
{
int V_41 ;
if ( V_38 == 0 ) {
* V_39 = 0 ;
* V_40 = 0 ;
return;
}
for ( V_41 = 0 ; V_42 [ V_41 ] . V_38 ; V_41 ++ ) {
if ( V_38 == V_42 [ V_41 ] . V_38 ) {
* V_39 = V_42 [ V_41 ] . V_43 ;
* V_40 = V_42 [ V_41 ] . V_44 ;
return;
}
}
* V_39 = V_45 ;
* V_40 = V_46 ;
}
int
F_13 ( char * V_47 , bool V_48 )
{
struct V_49 * V_50 = (struct V_49 * ) V_47 ;
unsigned int V_41 ;
int V_11 = - V_51 ;
T_2 V_52 ;
T_3 V_53 ;
if ( V_50 -> V_54 . V_55 == 0 )
return 0 ;
if ( V_50 -> V_56 & V_57 ) {
T_1 V_58 = F_14 ( V_50 -> V_54 . V_55 ) ;
if ( V_48 && ( V_58 != ( V_59 ) ) )
F_10 ( V_58 ) ;
else if ( V_60 & V_61 )
F_10 ( V_58 ) ;
F_12 ( V_58 , & V_52 , & V_53 ) ;
} else {
V_52 = V_50 -> V_54 . V_62 . V_63 ;
V_53 = F_15 ( V_50 -> V_54 . V_62 . Error ) ;
}
if ( V_52 == V_64 ) {
for ( V_41 = 0 ;
V_41 <
sizeof( V_65 ) /
sizeof( struct V_66 ) ; V_41 ++ ) {
if ( V_65 [ V_41 ] . V_67 == 0 )
break;
else if ( V_65 [ V_41 ] . V_67 ==
V_53 ) {
V_11 = V_65 [ V_41 ] . V_68 ;
break;
}
}
} else if ( V_52 == V_69 ) {
for ( V_41 = 0 ;
V_41 <
sizeof( V_70 ) /
sizeof( struct V_66 ) ; V_41 ++ ) {
if ( V_70 [ V_41 ] . V_67 == 0 )
break;
else if ( V_70 [ V_41 ] . V_67 ==
V_53 ) {
V_11 = V_70 [ V_41 ] . V_68 ;
break;
}
}
}
F_4 ( 1 , L_3 ,
F_14 ( V_50 -> V_54 . V_55 ) , V_11 ) ;
return V_11 ;
}
unsigned int
F_16 ( void * V_47 )
{
struct V_49 * V_71 = (struct V_49 * ) V_47 ;
return ( sizeof( struct V_49 ) + ( 2 * V_71 -> V_72 ) +
2 + F_17 ( V_71 ) ) ;
}
struct V_73
F_18 ( T_4 V_74 )
{
struct V_73 V_75 ;
T_5 V_76 ;
V_76 = F_19 ( V_74 ) - V_77 ;
V_75 . V_78 = F_20 ( V_76 , 10000000 ) * 100 ;
V_75 . V_79 = V_76 ;
return V_75 ;
}
T_5
F_21 ( struct V_73 V_76 )
{
return ( T_5 ) V_76 . V_79 * 10000000 + V_76 . V_78 / 100 + V_77 ;
}
struct V_73 F_22 ( T_6 V_80 , T_6 V_81 , int V_82 )
{
struct V_73 V_75 ;
int V_83 , V_84 , V_85 , V_86 , V_87 ;
T_7 V_88 = F_15 ( V_80 ) ;
T_7 time = F_15 ( V_81 ) ;
T_8 * V_89 = ( T_8 * ) & time ;
T_9 * V_90 = ( T_9 * ) & V_88 ;
F_4 ( 1 , L_4 , V_88 , time ) ;
V_83 = 2 * V_89 -> V_91 ;
V_84 = V_89 -> V_92 ;
if ( ( V_83 > 59 ) || ( V_84 > 59 ) )
F_23 ( 1 , L_5 , V_84 , V_83 ) ;
V_83 += ( V_84 * 60 ) ;
V_83 += 60 * 60 * V_89 -> V_93 ;
if ( V_89 -> V_93 > 24 )
F_23 ( 1 , L_6 , V_89 -> V_93 ) ;
V_85 = V_90 -> V_94 ;
V_86 = V_90 -> V_95 ;
if ( ( V_85 > 31 ) || ( V_86 > 12 ) ) {
F_23 ( 1 , L_7 , V_86 , V_85 ) ;
if ( V_86 > 12 )
V_86 = 12 ;
}
V_86 -= 1 ;
V_85 += V_96 [ V_86 ] ;
V_85 += 3652 ;
V_87 = V_90 -> V_97 ;
V_85 += V_87 * 365 ;
V_85 += ( V_87 / 4 ) ;
if ( V_87 >= 120 )
V_85 = V_85 - 1 ;
if ( V_87 != 120 )
V_85 -= ( ( V_87 & 0x03 ) == 0 ) && ( V_86 < 2 ? 1 : 0 ) ;
V_83 += 24 * 60 * 60 * V_85 ;
V_75 . V_79 = V_83 + V_82 ;
V_75 . V_78 = 0 ;
return V_75 ;
}
