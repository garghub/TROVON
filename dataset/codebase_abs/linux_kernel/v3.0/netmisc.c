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
V_11 = F_6 ( V_15 , 0 ,
( unsigned long * ) & V_19 -> V_26 ) ;
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
F_13 ( struct V_47 * V_48 , bool V_49 )
{
unsigned int V_41 ;
int V_11 = - V_50 ;
T_2 V_51 ;
T_3 V_52 ;
if ( V_48 -> V_53 . V_54 == 0 )
return 0 ;
if ( V_48 -> V_55 & V_56 ) {
T_1 V_57 = F_14 ( V_48 -> V_53 . V_54 ) ;
if ( V_49 && ( V_57 != ( V_58 ) ) )
F_10 ( V_57 ) ;
else if ( V_59 & V_60 )
F_10 ( V_57 ) ;
F_12 ( V_57 , & V_51 , & V_52 ) ;
} else {
V_51 = V_48 -> V_53 . V_61 . V_62 ;
V_52 = F_15 ( V_48 -> V_53 . V_61 . Error ) ;
}
if ( V_51 == V_63 ) {
for ( V_41 = 0 ;
V_41 <
sizeof( V_64 ) /
sizeof( struct V_65 ) ; V_41 ++ ) {
if ( V_64 [ V_41 ] . V_66 == 0 )
break;
else if ( V_64 [ V_41 ] . V_66 ==
V_52 ) {
V_11 = V_64 [ V_41 ] . V_67 ;
break;
}
}
} else if ( V_51 == V_68 ) {
for ( V_41 = 0 ;
V_41 <
sizeof( V_69 ) /
sizeof( struct V_65 ) ; V_41 ++ ) {
if ( V_69 [ V_41 ] . V_66 == 0 )
break;
else if ( V_69 [ V_41 ] . V_66 ==
V_52 ) {
V_11 = V_69 [ V_41 ] . V_67 ;
break;
}
}
}
F_4 ( 1 , L_3 ,
F_14 ( V_48 -> V_53 . V_54 ) , V_11 ) ;
return V_11 ;
}
unsigned int
F_16 ( struct V_47 * V_70 )
{
return ( sizeof( struct V_47 ) + ( 2 * V_70 -> V_71 ) +
2 + F_17 ( V_70 ) ) ;
}
struct V_72
F_18 ( T_4 V_73 )
{
struct V_72 V_74 ;
T_5 V_75 ;
V_75 = F_19 ( V_73 ) - V_76 ;
V_74 . V_77 = F_20 ( V_75 , 10000000 ) * 100 ;
V_74 . V_78 = V_75 ;
return V_74 ;
}
T_5
F_21 ( struct V_72 V_75 )
{
return ( T_5 ) V_75 . V_78 * 10000000 + V_75 . V_77 / 100 + V_76 ;
}
struct V_72 F_22 ( T_6 V_79 , T_6 V_80 , int V_81 )
{
struct V_72 V_74 ;
int V_82 , V_83 , V_84 , V_85 , V_86 ;
T_7 V_87 = F_15 ( V_79 ) ;
T_7 time = F_15 ( V_80 ) ;
T_8 * V_88 = ( T_8 * ) & time ;
T_9 * V_89 = ( T_9 * ) & V_87 ;
F_4 ( 1 , L_4 , V_87 , time ) ;
V_82 = 2 * V_88 -> V_90 ;
V_83 = V_88 -> V_91 ;
if ( ( V_82 > 59 ) || ( V_83 > 59 ) )
F_23 ( 1 , L_5 , V_83 , V_82 ) ;
V_82 += ( V_83 * 60 ) ;
V_82 += 60 * 60 * V_88 -> V_92 ;
if ( V_88 -> V_92 > 24 )
F_23 ( 1 , L_6 , V_88 -> V_92 ) ;
V_84 = V_89 -> V_93 ;
V_85 = V_89 -> V_94 ;
if ( ( V_84 > 31 ) || ( V_85 > 12 ) ) {
F_23 ( 1 , L_7 , V_85 , V_84 ) ;
if ( V_85 > 12 )
V_85 = 12 ;
}
V_85 -= 1 ;
V_84 += V_95 [ V_85 ] ;
V_84 += 3652 ;
V_86 = V_89 -> V_96 ;
V_84 += V_86 * 365 ;
V_84 += ( V_86 / 4 ) ;
if ( V_86 >= 120 )
V_84 = V_84 - 1 ;
if ( V_86 != 120 )
V_84 -= ( ( V_86 & 0x03 ) == 0 ) && ( V_85 < 2 ? 1 : 0 ) ;
V_82 += 24 * 60 * 60 * V_84 ;
V_74 . V_78 = V_82 + V_81 ;
V_74 . V_77 = 0 ;
return V_74 ;
}
