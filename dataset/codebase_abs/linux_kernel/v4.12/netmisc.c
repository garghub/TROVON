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
void
F_7 ( struct V_9 * V_27 , const unsigned short int V_28 )
{
switch ( V_27 -> V_29 ) {
case V_6 :
( (struct V_16 * ) V_27 ) -> V_30 = F_8 ( V_28 ) ;
break;
case V_7 :
( (struct V_18 * ) V_27 ) -> V_31 = F_8 ( V_28 ) ;
break;
}
}
static void
F_9 ( T_1 V_32 )
{
int V_33 = 0 ;
while ( V_34 [ V_33 ] . V_35 != NULL ) {
if ( ( ( V_34 [ V_33 ] . V_36 ) & 0xFFFFFF ) ==
( V_32 & 0xFFFFFF ) ) {
F_10 ( L_2 ,
V_32 , V_34 [ V_33 ] . V_35 ) ;
}
V_33 ++ ;
}
return;
}
static void
F_11 ( T_1 V_37 , T_2 * V_38 , T_3 * V_39 )
{
int V_40 ;
if ( V_37 == 0 ) {
* V_38 = 0 ;
* V_39 = 0 ;
return;
}
for ( V_40 = 0 ; V_41 [ V_40 ] . V_37 ; V_40 ++ ) {
if ( V_37 == V_41 [ V_40 ] . V_37 ) {
* V_38 = V_41 [ V_40 ] . V_42 ;
* V_39 = V_41 [ V_40 ] . V_43 ;
return;
}
}
* V_38 = V_44 ;
* V_39 = V_45 ;
}
int
F_12 ( char * V_46 , bool V_47 )
{
struct V_48 * V_49 = (struct V_48 * ) V_46 ;
unsigned int V_40 ;
int V_11 = - V_50 ;
T_2 V_51 ;
T_3 V_52 ;
if ( V_49 -> V_53 . V_54 == 0 )
return 0 ;
if ( V_49 -> V_55 & V_56 ) {
T_1 V_57 = F_13 ( V_49 -> V_53 . V_54 ) ;
if ( V_47 && ( V_57 != ( V_58 ) ) )
F_9 ( V_57 ) ;
else if ( V_59 & V_60 )
F_9 ( V_57 ) ;
F_11 ( V_57 , & V_51 , & V_52 ) ;
} else {
V_51 = V_49 -> V_53 . V_61 . V_62 ;
V_52 = F_14 ( V_49 -> V_53 . V_61 . Error ) ;
}
if ( V_51 == V_63 ) {
for ( V_40 = 0 ;
V_40 <
sizeof( V_64 ) /
sizeof( struct V_65 ) ; V_40 ++ ) {
if ( V_64 [ V_40 ] . V_66 == 0 )
break;
else if ( V_64 [ V_40 ] . V_66 ==
V_52 ) {
V_11 = V_64 [ V_40 ] . V_67 ;
break;
}
}
} else if ( V_51 == V_68 ) {
for ( V_40 = 0 ;
V_40 <
sizeof( V_69 ) /
sizeof( struct V_65 ) ; V_40 ++ ) {
if ( V_69 [ V_40 ] . V_66 == 0 )
break;
else if ( V_69 [ V_40 ] . V_66 ==
V_52 ) {
V_11 = V_69 [ V_40 ] . V_67 ;
break;
}
}
}
F_4 ( V_70 , L_3 ,
F_13 ( V_49 -> V_53 . V_54 ) , V_11 ) ;
return V_11 ;
}
unsigned int
F_15 ( void * V_46 )
{
struct V_48 * V_71 = (struct V_48 * ) V_46 ;
return ( sizeof( struct V_48 ) + ( 2 * V_71 -> V_72 ) +
2 + F_16 ( V_71 ) ) ;
}
struct V_73
F_17 ( T_4 V_74 )
{
struct V_73 V_75 ;
T_5 V_76 = F_18 ( V_74 ) - V_77 ;
T_6 V_78 ;
if ( V_76 < 0 ) {
V_78 = - V_76 ;
V_75 . V_79 = ( long ) ( F_19 ( V_78 , 10000000 ) * 100 ) ;
V_75 . V_79 = - V_75 . V_79 ;
V_75 . V_80 = - V_78 ;
} else {
V_78 = V_76 ;
V_75 . V_79 = ( long ) F_19 ( V_78 , 10000000 ) * 100 ;
V_75 . V_80 = V_78 ;
}
return V_75 ;
}
T_6
F_20 ( struct V_73 V_76 )
{
return ( T_6 ) V_76 . V_80 * 10000000 + V_76 . V_79 / 100 + V_77 ;
}
struct V_73 F_21 ( T_7 V_81 , T_7 V_82 , int V_83 )
{
struct V_73 V_75 ;
int V_84 , V_85 , V_86 , V_87 , V_88 ;
T_8 V_89 = F_14 ( V_81 ) ;
T_8 time = F_14 ( V_82 ) ;
T_9 * V_90 = ( T_9 * ) & time ;
T_10 * V_91 = ( T_10 * ) & V_89 ;
F_4 ( V_70 , L_4 , V_89 , time ) ;
V_84 = 2 * V_90 -> V_92 ;
V_85 = V_90 -> V_93 ;
if ( ( V_84 > 59 ) || ( V_85 > 59 ) )
F_4 ( V_94 , L_5 , V_85 , V_84 ) ;
V_84 += ( V_85 * 60 ) ;
V_84 += 60 * 60 * V_90 -> V_95 ;
if ( V_90 -> V_95 > 24 )
F_4 ( V_94 , L_6 , V_90 -> V_95 ) ;
V_86 = V_91 -> V_96 ;
V_87 = V_91 -> V_97 ;
if ( V_86 < 1 || V_86 > 31 || V_87 < 1 || V_87 > 12 ) {
F_4 ( V_94 , L_7 , V_87 , V_86 ) ;
V_86 = F_22 ( V_86 , 1 , 31 ) ;
V_87 = F_22 ( V_87 , 1 , 12 ) ;
}
V_87 -= 1 ;
V_86 += V_98 [ V_87 ] ;
V_86 += 3652 ;
V_88 = V_91 -> V_99 ;
V_86 += V_88 * 365 ;
V_86 += ( V_88 / 4 ) ;
if ( V_88 >= 120 )
V_86 = V_86 - 1 ;
if ( V_88 != 120 )
V_86 -= ( ( V_88 & 0x03 ) == 0 ) && ( V_87 < 2 ? 1 : 0 ) ;
V_84 += 24 * 60 * 60 * V_86 ;
V_75 . V_80 = V_84 + V_83 ;
V_75 . V_79 = 0 ;
return V_75 ;
}
