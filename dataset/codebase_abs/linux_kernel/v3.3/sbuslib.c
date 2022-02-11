void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_5 )
{
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
V_2 -> V_6 = F_2 ( V_4 , L_1 , 1152 ) ;
V_2 -> V_7 = F_2 ( V_4 , L_2 , 900 ) ;
V_2 -> V_8 = V_2 -> V_6 ;
V_2 -> V_9 = V_2 -> V_7 ;
V_2 -> V_10 = V_5 ;
}
static unsigned long F_3 ( long V_11 , unsigned long V_12 )
{
if ( V_11 == V_13 ) return 0 ;
if ( V_11 >= 0 ) return V_11 ;
return V_12 * ( - V_11 ) ;
}
int F_4 ( struct V_14 * V_15 ,
unsigned long V_16 ,
unsigned long V_12 ,
unsigned long V_17 ,
struct V_18 * V_19 )
{
unsigned int V_11 , V_20 , V_21 , V_22 ;
unsigned long V_23 = 0 ;
unsigned long V_24 ;
int V_25 ;
if ( ! ( V_19 -> V_26 & ( V_27 | V_28 ) ) )
return - V_29 ;
V_11 = V_19 -> V_30 - V_19 -> V_31 ;
if ( V_19 -> V_32 > ( ~ 0UL >> V_33 ) )
return - V_29 ;
V_24 = V_19 -> V_32 << V_33 ;
V_19 -> V_26 |= ( V_34 | V_35 ) ;
V_19 -> V_36 = F_5 ( V_19 -> V_36 ) ;
for ( V_20 = 0 ; V_20 < V_11 ; ) {
V_22 = 0 ;
for ( V_25 = 0 ; V_15 [ V_25 ] . V_11 ; V_25 ++ )
if ( V_15 [ V_25 ] . V_37 == V_24 + V_20 ) {
V_22 = F_3 ( V_15 [ V_25 ] . V_11 , V_12 ) ;
#ifdef F_6
#define F_7 (PAGE_MASK|0x1UL)
#else
#define F_7 (PAGE_MASK)
#endif
V_23 = ( V_16 + V_15 [ V_25 ] . V_38 ) & F_7 ;
break;
}
if ( ! V_22 ) {
V_20 += V_39 ;
continue;
}
if ( V_20 + V_22 > V_11 )
V_22 = V_11 - V_20 ;
V_21 = F_8 ( V_19 ,
V_19 -> V_31 + V_20 ,
F_9 ( V_17 ,
V_23 >> V_33 ) ,
V_22 ,
V_19 -> V_36 ) ;
if ( V_21 )
return - V_40 ;
V_20 += V_22 ;
}
return 0 ;
}
int F_10 ( unsigned long V_41 , unsigned long V_42 ,
struct V_43 * V_44 ,
int type , int V_45 , unsigned long V_46 )
{
switch( V_41 ) {
case V_47 : {
struct V_48 T_1 * V_49 = (struct V_48 T_1 * ) V_42 ;
if ( F_11 ( type , & V_49 -> V_50 ) ||
F_12 ( V_44 -> V_2 . V_7 , & V_49 -> V_51 ) ||
F_12 ( V_44 -> V_2 . V_6 , & V_49 -> V_52 ) ||
F_12 ( V_45 , & V_49 -> V_45 ) ||
F_12 ( 0 , & V_49 -> V_53 ) ||
F_12 ( V_46 , & V_49 -> V_53 ) )
return - V_54 ;
return 0 ;
}
case V_55 : {
struct V_56 T_1 * V_57 = (struct V_56 T_1 * ) V_42 ;
struct V_58 V_59 ;
T_2 V_60 , V_61 , V_62 ;
T_3 V_63 , V_64 , V_65 ;
unsigned char T_1 * V_66 ;
unsigned char T_1 * V_67 ;
unsigned char T_1 * V_68 ;
int V_69 , V_70 , V_25 ;
if ( F_13 ( V_69 , & V_57 -> V_69 ) ||
F_14 ( V_70 , & V_57 -> V_70 ) ||
F_14 ( V_66 , & V_57 -> V_60 ) ||
F_14 ( V_67 , & V_57 -> V_61 ) ||
F_14 ( V_68 , & V_57 -> V_62 ) )
return - V_54 ;
V_59 . V_71 = 1 ;
V_59 . V_60 = & V_60 ;
V_59 . V_61 = & V_61 ;
V_59 . V_62 = & V_62 ;
V_59 . V_72 = NULL ;
for ( V_25 = 0 ; V_25 < V_70 ; V_25 ++ ) {
int V_73 ;
if ( F_13 ( V_63 , & V_66 [ V_25 ] ) ||
F_13 ( V_64 , & V_67 [ V_25 ] ) ||
F_13 ( V_65 , & V_68 [ V_25 ] ) )
return - V_54 ;
V_60 = V_63 << 8 ;
V_61 = V_64 << 8 ;
V_62 = V_65 << 8 ;
V_59 . V_74 = V_69 + V_25 ;
V_73 = F_15 ( & V_59 , V_44 ) ;
if ( V_73 )
return V_73 ;
}
return 0 ;
}
case V_75 : {
struct V_56 T_1 * V_57 = (struct V_56 T_1 * ) V_42 ;
unsigned char T_1 * V_66 ;
unsigned char T_1 * V_67 ;
unsigned char T_1 * V_68 ;
struct V_58 * V_59 = & V_44 -> V_59 ;
int V_69 , V_70 , V_25 ;
T_3 V_60 , V_61 , V_62 ;
if ( F_13 ( V_69 , & V_57 -> V_69 ) ||
F_14 ( V_70 , & V_57 -> V_70 ) ||
F_14 ( V_66 , & V_57 -> V_60 ) ||
F_14 ( V_67 , & V_57 -> V_61 ) ||
F_14 ( V_68 , & V_57 -> V_62 ) )
return - V_54 ;
if ( V_69 + V_70 > V_59 -> V_71 )
return - V_29 ;
for ( V_25 = 0 ; V_25 < V_70 ; V_25 ++ ) {
V_60 = V_59 -> V_60 [ V_69 + V_25 ] >> 8 ;
V_61 = V_59 -> V_61 [ V_69 + V_25 ] >> 8 ;
V_62 = V_59 -> V_62 [ V_69 + V_25 ] >> 8 ;
if ( F_11 ( V_60 , & V_66 [ V_25 ] ) ||
F_11 ( V_61 , & V_67 [ V_25 ] ) ||
F_11 ( V_62 , & V_68 [ V_25 ] ) )
return - V_54 ;
}
return 0 ;
}
default:
return - V_29 ;
} ;
}
static int F_16 ( struct V_43 * V_44 , unsigned int V_41 , unsigned long V_42 )
{
struct V_76 T_1 * V_77 = ( void T_1 * ) V_42 ;
struct V_56 T_1 * V_78 = F_17 ( sizeof( * V_78 ) ) ;
T_4 V_79 ;
int V_80 ;
V_80 = F_18 ( V_78 , V_77 , 2 * sizeof( int ) ) ;
V_80 |= F_13 ( V_79 , & V_77 -> V_60 ) ;
V_80 |= F_11 ( F_19 ( V_79 ) , & V_78 -> V_60 ) ;
V_80 |= F_13 ( V_79 , & V_77 -> V_61 ) ;
V_80 |= F_11 ( F_19 ( V_79 ) , & V_78 -> V_61 ) ;
V_80 |= F_13 ( V_79 , & V_77 -> V_62 ) ;
V_80 |= F_11 ( F_19 ( V_79 ) , & V_78 -> V_62 ) ;
if ( V_80 )
return - V_54 ;
return V_44 -> V_81 -> V_82 ( V_44 ,
( V_41 == V_83 ) ?
V_55 : V_75 ,
( unsigned long ) V_78 ) ;
}
static int F_20 ( struct V_43 * V_44 , unsigned long V_42 )
{
struct V_84 T_1 * V_78 = F_17 ( sizeof( * V_78 ) ) ;
struct V_85 T_1 * V_77 = ( void T_1 * ) V_42 ;
T_5 V_79 ;
int V_80 ;
V_80 = F_18 ( V_78 , V_77 ,
2 * sizeof ( short ) + 2 * sizeof( struct V_86 ) ) ;
V_80 |= F_18 ( & V_78 -> V_11 , & V_77 -> V_11 , sizeof( struct V_86 ) ) ;
V_80 |= F_18 ( & V_78 -> V_59 , & V_77 -> V_59 , 2 * sizeof( int ) ) ;
V_80 |= F_13 ( V_79 , & V_77 -> V_59 . V_60 ) ;
V_80 |= F_11 ( F_19 ( V_79 ) , & V_78 -> V_59 . V_60 ) ;
V_80 |= F_13 ( V_79 , & V_77 -> V_59 . V_61 ) ;
V_80 |= F_11 ( F_19 ( V_79 ) , & V_78 -> V_59 . V_61 ) ;
V_80 |= F_13 ( V_79 , & V_77 -> V_59 . V_62 ) ;
V_80 |= F_11 ( F_19 ( V_79 ) , & V_78 -> V_59 . V_62 ) ;
V_80 |= F_13 ( V_79 , & V_77 -> V_87 ) ;
V_80 |= F_11 ( F_19 ( V_79 ) , & V_78 -> V_87 ) ;
V_80 |= F_13 ( V_79 , & V_77 -> V_88 ) ;
V_80 |= F_11 ( F_19 ( V_79 ) , & V_78 -> V_88 ) ;
if ( V_80 )
return - V_54 ;
return V_44 -> V_81 -> V_82 ( V_44 , V_89 , ( unsigned long ) V_78 ) ;
}
int F_21 ( struct V_43 * V_44 , unsigned int V_41 , unsigned long V_42 )
{
switch ( V_41 ) {
case V_47 :
case V_90 :
case V_91 :
case V_92 :
case V_93 :
case V_94 :
case V_95 :
case V_96 :
case V_97 :
return V_44 -> V_81 -> V_82 ( V_44 , V_41 , V_42 ) ;
case V_83 :
return F_16 ( V_44 , V_41 , V_42 ) ;
case V_98 :
return F_16 ( V_44 , V_41 , V_42 ) ;
case V_99 :
return F_20 ( V_44 , V_42 ) ;
default:
return - V_100 ;
}
}
