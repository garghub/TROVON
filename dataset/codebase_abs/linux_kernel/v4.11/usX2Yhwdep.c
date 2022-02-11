static int F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
struct V_4 * V_4 ;
void * V_5 ;
F_2 ( L_1 ,
V_2 -> V_6 -> V_7 ,
V_2 -> V_8 ) ;
V_3 = V_2 -> V_8 << V_9 ;
V_5 = ( char * ) ( (struct V_10 * ) V_2 -> V_6 -> V_11 ) -> V_12 + V_3 ;
V_4 = F_3 ( V_5 ) ;
F_4 ( V_4 ) ;
V_2 -> V_4 = V_4 ;
F_2 ( L_2 ,
V_5 , V_4 ) ;
return 0 ;
}
static int F_5 ( struct V_13 * V_14 , struct V_15 * V_16 , struct V_17 * V_18 )
{
unsigned long V_19 = ( unsigned long ) ( V_18 -> V_20 - V_18 -> V_7 ) ;
struct V_10 * V_21 = V_14 -> V_22 ;
if ( ! ( V_21 -> V_23 & V_24 ) )
return - V_25 ;
if ( V_19 > F_6 ( sizeof( struct V_12 ) ) ) {
F_7 ( L_3 , V_19 , ( unsigned long ) sizeof( struct V_12 ) ) ;
return - V_26 ;
}
if ( ! V_21 -> V_12 ) {
F_8 ( & V_21 -> V_27 ) ;
if( ! ( V_21 -> V_12 = F_9 ( sizeof( struct V_12 ) , V_28 ) ) )
return - V_29 ;
memset ( V_21 -> V_12 , - 1 , sizeof( struct V_12 ) ) ;
V_21 -> V_12 -> V_30 = - 2 ;
}
V_18 -> V_31 = & V_32 ;
V_18 -> V_33 |= V_34 | V_35 ;
V_18 -> V_11 = V_14 -> V_22 ;
return 0 ;
}
static unsigned int F_10 ( struct V_13 * V_14 , struct V_15 * V_15 , T_1 * V_36 )
{
unsigned int V_37 = 0 ;
struct V_10 * V_21 = V_14 -> V_22 ;
struct V_12 * V_38 = V_21 -> V_12 ;
if ( V_21 -> V_23 & V_39 )
return V_40 ;
F_11 ( V_15 , & V_21 -> V_27 , V_36 ) ;
if ( V_38 != NULL && V_38 -> V_30 != V_38 -> V_41 )
V_37 |= V_42 ;
return V_37 ;
}
static int F_12 ( struct V_13 * V_14 ,
struct V_43 * V_44 )
{
static char * V_45 [ V_46 ] = {
[ V_47 ] = L_4 ,
[ V_48 ] = L_5 ,
[ V_49 ] = L_6 ,
} ;
struct V_10 * V_21 = V_14 -> V_22 ;
int V_50 = - 1 ;
switch ( F_13 ( V_21 -> V_51 -> V_52 . V_53 ) ) {
case V_54 :
V_50 = V_47 ;
break;
case V_55 :
V_50 = V_48 ;
break;
case V_56 :
V_50 = V_49 ;
break;
}
if ( 0 > V_50 )
return - V_57 ;
strcpy ( V_44 -> V_50 , V_45 [ V_50 ] ) ;
V_44 -> V_58 = 2 ;
if ( V_21 -> V_23 & V_24 )
V_44 -> V_59 = 1 ;
V_44 -> V_60 = V_61 ;
return 0 ;
}
static int F_14 ( struct V_62 * V_63 )
{
static struct V_64 V_65 = {
. V_66 = 0x06 ,
. V_67 = 0x06 ,
. V_68 = 0x001 ,
. V_69 = 0x001
} ;
static struct V_70 V_71 = {
. V_72 = L_7 ,
. V_73 = V_74 ,
. V_75 = 0 ,
. type = V_76 ,
. V_77 = & V_65
} ;
static struct V_64 V_78 = {
. V_66 = 0x06 ,
. V_67 = 0x06 ,
. V_68 = 0x003 ,
. V_69 = 0x003
} ;
static struct V_70 V_79 = {
. V_72 = L_7 ,
. V_73 = L_8 ,
. V_75 = 0 ,
. type = V_76 ,
. V_77 = & V_78
} ;
struct V_80 * V_51 = F_15 ( V_63 ) -> V_51 ;
struct V_81 * V_82 = F_16 ( V_51 , 0 ) ;
struct V_70 * V_83 =
F_13 ( V_51 -> V_52 . V_53 ) == V_56 ?
& V_79 : & V_71 ;
F_2 ( L_9 ) ;
return F_17 ( V_63 , V_82 , & F_15 ( V_63 ) -> V_84 , V_83 ) ;
}
static int F_18 ( struct V_62 * V_63 )
{
int V_85 ;
do {
if ( ( V_85 = F_14 ( V_63 ) ) < 0 ) {
F_19 ( V_86 L_10 , V_85 ) ;
break;
}
if ( ( V_85 = F_20 ( V_63 ) ) < 0 )
break;
if ( ( V_85 = F_21 ( V_63 ) ) < 0 )
break;
if ( ( V_85 = F_22 ( V_63 ) ) < 0 )
break;
} while ( 0 );
return V_85 ;
}
static int F_23 ( struct V_13 * V_14 ,
struct V_87 * V_88 )
{
struct V_10 * V_89 = V_14 -> V_22 ;
int V_90 , V_85 = - V_26 ;
F_2 ( L_11 , V_88 -> V_91 ) ;
if ( F_24 ( V_92 , V_88 -> V_93 , V_88 -> V_94 ) ) {
struct V_80 * V_51 = V_89 -> V_51 ;
char * V_95 ;
V_95 = F_25 ( V_88 -> V_93 , V_88 -> V_94 ) ;
if ( F_26 ( V_95 ) )
return F_27 ( V_95 ) ;
V_85 = F_28 ( V_51 , 0 , 1 ) ;
if ( V_85 )
F_19 ( V_86 L_12 ) ;
else
V_85 = F_29 ( V_51 , F_30 ( V_51 , 2 ) , V_95 , V_88 -> V_94 , & V_90 , 6000 ) ;
F_31 ( V_95 ) ;
}
if ( V_85 )
return V_85 ;
if ( V_88 -> V_96 == 1 ) {
F_32 ( 250 ) ;
V_85 = F_33 ( V_89 ) ;
if ( V_85 ) {
F_19 ( V_86 L_13 ) ;
return V_85 ;
}
V_85 = F_34 ( V_89 ) ;
if ( V_85 ) {
F_19 ( V_86 L_14 ) ;
return V_85 ;
}
V_85 = F_18 ( V_14 -> V_63 ) ;
if ( V_85 ) {
F_19 ( V_86 L_15 , V_85 ) ;
F_35 ( V_14 -> V_63 ) ;
return V_85 ;
}
V_89 -> V_23 |= V_24 ;
F_2 ( L_16 , V_14 -> V_91 ) ;
}
return V_85 ;
}
int F_36 ( struct V_62 * V_63 , struct V_80 * V_97 )
{
int V_85 ;
struct V_13 * V_14 ;
if ( ( V_85 = F_37 ( V_63 , V_98 , 0 , & V_14 ) ) < 0 )
return V_85 ;
V_14 -> V_82 = V_99 ;
V_14 -> V_22 = F_15 ( V_63 ) ;
V_14 -> V_100 . V_101 = F_12 ;
V_14 -> V_100 . V_102 = F_23 ;
V_14 -> V_100 . V_103 = F_5 ;
V_14 -> V_100 . V_104 = F_10 ;
V_14 -> V_105 = 1 ;
sprintf ( V_14 -> V_91 , L_17 , V_97 -> V_106 -> V_107 , V_97 -> V_108 ) ;
return 0 ;
}
