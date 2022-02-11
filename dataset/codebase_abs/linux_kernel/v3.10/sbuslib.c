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
V_19 -> V_34 = F_5 ( V_19 -> V_34 ) ;
for ( V_20 = 0 ; V_20 < V_11 ; ) {
V_22 = 0 ;
for ( V_25 = 0 ; V_15 [ V_25 ] . V_11 ; V_25 ++ )
if ( V_15 [ V_25 ] . V_35 == V_24 + V_20 ) {
V_22 = F_3 ( V_15 [ V_25 ] . V_11 , V_12 ) ;
#ifdef F_6
#define F_7 (PAGE_MASK|0x1UL)
#else
#define F_7 (PAGE_MASK)
#endif
V_23 = ( V_16 + V_15 [ V_25 ] . V_36 ) & F_7 ;
break;
}
if ( ! V_22 ) {
V_20 += V_37 ;
continue;
}
if ( V_20 + V_22 > V_11 )
V_22 = V_11 - V_20 ;
V_21 = F_8 ( V_19 ,
V_19 -> V_31 + V_20 ,
F_9 ( V_17 ,
V_23 >> V_33 ) ,
V_22 ,
V_19 -> V_34 ) ;
if ( V_21 )
return - V_38 ;
V_20 += V_22 ;
}
return 0 ;
}
int F_10 ( unsigned long V_39 , unsigned long V_40 ,
struct V_41 * V_42 ,
int type , int V_43 , unsigned long V_44 )
{
switch( V_39 ) {
case V_45 : {
struct V_46 T_1 * V_47 = (struct V_46 T_1 * ) V_40 ;
if ( F_11 ( type , & V_47 -> V_48 ) ||
F_12 ( V_42 -> V_2 . V_7 , & V_47 -> V_49 ) ||
F_12 ( V_42 -> V_2 . V_6 , & V_47 -> V_50 ) ||
F_12 ( V_43 , & V_47 -> V_43 ) ||
F_12 ( 0 , & V_47 -> V_51 ) ||
F_12 ( V_44 , & V_47 -> V_51 ) )
return - V_52 ;
return 0 ;
}
case V_53 : {
struct V_54 T_1 * V_55 = (struct V_54 T_1 * ) V_40 ;
struct V_56 V_57 ;
T_2 V_58 , V_59 , V_60 ;
T_3 V_61 , V_62 , V_63 ;
unsigned char T_1 * V_64 ;
unsigned char T_1 * V_65 ;
unsigned char T_1 * V_66 ;
int V_67 , V_68 , V_25 ;
if ( F_13 ( V_67 , & V_55 -> V_67 ) ||
F_14 ( V_68 , & V_55 -> V_68 ) ||
F_14 ( V_64 , & V_55 -> V_58 ) ||
F_14 ( V_65 , & V_55 -> V_59 ) ||
F_14 ( V_66 , & V_55 -> V_60 ) )
return - V_52 ;
V_57 . V_69 = 1 ;
V_57 . V_58 = & V_58 ;
V_57 . V_59 = & V_59 ;
V_57 . V_60 = & V_60 ;
V_57 . V_70 = NULL ;
for ( V_25 = 0 ; V_25 < V_68 ; V_25 ++ ) {
int V_71 ;
if ( F_13 ( V_61 , & V_64 [ V_25 ] ) ||
F_13 ( V_62 , & V_65 [ V_25 ] ) ||
F_13 ( V_63 , & V_66 [ V_25 ] ) )
return - V_52 ;
V_58 = V_61 << 8 ;
V_59 = V_62 << 8 ;
V_60 = V_63 << 8 ;
V_57 . V_72 = V_67 + V_25 ;
V_71 = F_15 ( & V_57 , V_42 ) ;
if ( V_71 )
return V_71 ;
}
return 0 ;
}
case V_73 : {
struct V_54 T_1 * V_55 = (struct V_54 T_1 * ) V_40 ;
unsigned char T_1 * V_64 ;
unsigned char T_1 * V_65 ;
unsigned char T_1 * V_66 ;
struct V_56 * V_57 = & V_42 -> V_57 ;
int V_67 , V_68 , V_25 ;
T_3 V_58 , V_59 , V_60 ;
if ( F_13 ( V_67 , & V_55 -> V_67 ) ||
F_14 ( V_68 , & V_55 -> V_68 ) ||
F_14 ( V_64 , & V_55 -> V_58 ) ||
F_14 ( V_65 , & V_55 -> V_59 ) ||
F_14 ( V_66 , & V_55 -> V_60 ) )
return - V_52 ;
if ( V_67 + V_68 > V_57 -> V_69 )
return - V_29 ;
for ( V_25 = 0 ; V_25 < V_68 ; V_25 ++ ) {
V_58 = V_57 -> V_58 [ V_67 + V_25 ] >> 8 ;
V_59 = V_57 -> V_59 [ V_67 + V_25 ] >> 8 ;
V_60 = V_57 -> V_60 [ V_67 + V_25 ] >> 8 ;
if ( F_11 ( V_58 , & V_64 [ V_25 ] ) ||
F_11 ( V_59 , & V_65 [ V_25 ] ) ||
F_11 ( V_60 , & V_66 [ V_25 ] ) )
return - V_52 ;
}
return 0 ;
}
default:
return - V_29 ;
} ;
}
static int F_16 ( struct V_41 * V_42 , unsigned int V_39 , unsigned long V_40 )
{
struct V_74 T_1 * V_75 = ( void T_1 * ) V_40 ;
struct V_54 T_1 * V_76 = F_17 ( sizeof( * V_76 ) ) ;
T_4 V_77 ;
int V_78 ;
V_78 = F_18 ( V_76 , V_75 , 2 * sizeof( int ) ) ;
V_78 |= F_13 ( V_77 , & V_75 -> V_58 ) ;
V_78 |= F_11 ( F_19 ( V_77 ) , & V_76 -> V_58 ) ;
V_78 |= F_13 ( V_77 , & V_75 -> V_59 ) ;
V_78 |= F_11 ( F_19 ( V_77 ) , & V_76 -> V_59 ) ;
V_78 |= F_13 ( V_77 , & V_75 -> V_60 ) ;
V_78 |= F_11 ( F_19 ( V_77 ) , & V_76 -> V_60 ) ;
if ( V_78 )
return - V_52 ;
return V_42 -> V_79 -> V_80 ( V_42 ,
( V_39 == V_81 ) ?
V_53 : V_73 ,
( unsigned long ) V_76 ) ;
}
static int F_20 ( struct V_41 * V_42 , unsigned long V_40 )
{
struct V_82 T_1 * V_76 = F_17 ( sizeof( * V_76 ) ) ;
struct V_83 T_1 * V_75 = ( void T_1 * ) V_40 ;
T_5 V_77 ;
int V_78 ;
V_78 = F_18 ( V_76 , V_75 ,
2 * sizeof ( short ) + 2 * sizeof( struct V_84 ) ) ;
V_78 |= F_18 ( & V_76 -> V_11 , & V_75 -> V_11 , sizeof( struct V_84 ) ) ;
V_78 |= F_18 ( & V_76 -> V_57 , & V_75 -> V_57 , 2 * sizeof( int ) ) ;
V_78 |= F_13 ( V_77 , & V_75 -> V_57 . V_58 ) ;
V_78 |= F_11 ( F_19 ( V_77 ) , & V_76 -> V_57 . V_58 ) ;
V_78 |= F_13 ( V_77 , & V_75 -> V_57 . V_59 ) ;
V_78 |= F_11 ( F_19 ( V_77 ) , & V_76 -> V_57 . V_59 ) ;
V_78 |= F_13 ( V_77 , & V_75 -> V_57 . V_60 ) ;
V_78 |= F_11 ( F_19 ( V_77 ) , & V_76 -> V_57 . V_60 ) ;
V_78 |= F_13 ( V_77 , & V_75 -> V_85 ) ;
V_78 |= F_11 ( F_19 ( V_77 ) , & V_76 -> V_85 ) ;
V_78 |= F_13 ( V_77 , & V_75 -> V_86 ) ;
V_78 |= F_11 ( F_19 ( V_77 ) , & V_76 -> V_86 ) ;
if ( V_78 )
return - V_52 ;
return V_42 -> V_79 -> V_80 ( V_42 , V_87 , ( unsigned long ) V_76 ) ;
}
int F_21 ( struct V_41 * V_42 , unsigned int V_39 , unsigned long V_40 )
{
switch ( V_39 ) {
case V_45 :
case V_88 :
case V_89 :
case V_90 :
case V_91 :
case V_92 :
case V_93 :
case V_94 :
case V_95 :
return V_42 -> V_79 -> V_80 ( V_42 , V_39 , V_40 ) ;
case V_81 :
return F_16 ( V_42 , V_39 , V_40 ) ;
case V_96 :
return F_16 ( V_42 , V_39 , V_40 ) ;
case V_97 :
return F_20 ( V_42 , V_40 ) ;
default:
return - V_98 ;
}
}
