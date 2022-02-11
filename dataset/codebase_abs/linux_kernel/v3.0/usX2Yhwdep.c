static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
unsigned long V_5 ;
struct V_6 * V_6 ;
void * V_7 ;
F_2 ( L_1 ,
V_2 -> V_8 ,
V_4 -> V_9 ) ;
V_5 = V_4 -> V_9 << V_10 ;
V_7 = ( char * ) ( (struct V_11 * ) V_2 -> V_12 ) -> V_13 + V_5 ;
V_6 = F_3 ( V_7 ) ;
F_4 ( V_6 ) ;
V_4 -> V_6 = V_6 ;
F_2 ( L_2 ,
V_7 , V_6 ) ;
return 0 ;
}
static int F_5 ( struct V_14 * V_15 , struct V_16 * V_17 , struct V_1 * V_2 )
{
unsigned long V_18 = ( unsigned long ) ( V_2 -> V_19 - V_2 -> V_8 ) ;
struct V_11 * V_20 = V_15 -> V_21 ;
if ( ! ( V_20 -> V_22 & V_23 ) )
return - V_24 ;
if ( V_18 > F_6 ( sizeof( struct V_13 ) ) ) {
F_7 ( L_3 , V_18 , ( unsigned long ) sizeof( struct V_13 ) ) ;
return - V_25 ;
}
if ( ! V_20 -> V_13 ) {
F_8 ( & V_20 -> V_26 ) ;
if( ! ( V_20 -> V_13 = F_9 ( sizeof( struct V_13 ) , V_27 ) ) )
return - V_28 ;
memset ( V_20 -> V_13 , - 1 , sizeof( struct V_13 ) ) ;
V_20 -> V_13 -> V_29 = - 2 ;
}
V_2 -> V_30 = & V_31 ;
V_2 -> V_32 |= V_33 | V_34 ;
V_2 -> V_12 = V_15 -> V_21 ;
return 0 ;
}
static unsigned int F_10 ( struct V_14 * V_15 , struct V_16 * V_16 , T_1 * V_35 )
{
unsigned int V_36 = 0 ;
struct V_11 * V_20 = V_15 -> V_21 ;
struct V_13 * V_37 = V_20 -> V_13 ;
if ( V_20 -> V_22 & V_38 )
return V_39 ;
F_11 ( V_16 , & V_20 -> V_26 , V_35 ) ;
if ( V_37 != NULL && V_37 -> V_29 != V_37 -> V_40 )
V_36 |= V_41 ;
return V_36 ;
}
static int F_12 ( struct V_14 * V_15 ,
struct V_42 * V_43 )
{
static char * V_44 [ V_45 ] = {
[ V_46 ] = L_4 ,
[ V_47 ] = L_5 ,
[ V_48 ] = L_6 ,
} ;
struct V_11 * V_20 = V_15 -> V_21 ;
int V_49 = - 1 ;
switch ( F_13 ( V_20 -> V_50 -> V_51 . V_52 ) ) {
case V_53 :
V_49 = V_46 ;
break;
case V_54 :
V_49 = V_47 ;
break;
case V_55 :
V_49 = V_48 ;
break;
}
if ( 0 > V_49 )
return - V_56 ;
strcpy ( V_43 -> V_49 , V_44 [ V_49 ] ) ;
V_43 -> V_57 = 2 ;
if ( V_20 -> V_22 & V_23 )
V_43 -> V_58 = 1 ;
V_43 -> V_59 = V_60 ;
return 0 ;
}
static int F_14 ( struct V_61 * V_62 )
{
static struct V_63 V_64 = {
. V_65 = 0x06 ,
. V_66 = 0x06 ,
. V_67 = 0x001 ,
. V_68 = 0x001
} ;
static struct V_69 V_70 = {
. V_71 = L_7 ,
. V_72 = V_73 ,
. V_74 = 0 ,
. type = V_75 ,
. V_76 = & V_64
} ;
static struct V_63 V_77 = {
. V_65 = 0x06 ,
. V_66 = 0x06 ,
. V_67 = 0x003 ,
. V_68 = 0x003
} ;
static struct V_69 V_78 = {
. V_71 = L_7 ,
. V_72 = L_8 ,
. V_74 = 0 ,
. type = V_75 ,
. V_76 = & V_77
} ;
struct V_79 * V_50 = F_15 ( V_62 ) -> V_50 ;
struct V_80 * V_81 = F_16 ( V_50 , 0 ) ;
struct V_69 * V_82 =
F_13 ( V_50 -> V_51 . V_52 ) == V_55 ?
& V_78 : & V_70 ;
F_2 ( L_9 ) ;
return F_17 ( V_62 , V_81 , & F_15 ( V_62 ) -> V_83 , V_82 ) ;
}
static int F_18 ( struct V_61 * V_62 )
{
int V_84 ;
do {
if ( ( V_84 = F_14 ( V_62 ) ) < 0 ) {
F_19 ( V_85 L_10 , V_84 ) ;
break;
}
if ( ( V_84 = F_20 ( V_62 ) ) < 0 )
break;
if ( ( V_84 = F_21 ( V_62 ) ) < 0 )
break;
if ( ( V_84 = F_22 ( V_62 ) ) < 0 )
break;
} while ( 0 );
return V_84 ;
}
static int F_23 ( struct V_14 * V_15 ,
struct V_86 * V_87 )
{
struct V_11 * V_88 = V_15 -> V_21 ;
int V_89 , V_84 = - V_25 ;
F_2 ( L_11 , V_87 -> V_90 ) ;
if ( F_24 ( V_91 , V_87 -> V_92 , V_87 -> V_93 ) ) {
struct V_79 * V_50 = V_88 -> V_50 ;
char * V_94 ;
V_94 = F_25 ( V_87 -> V_92 , V_87 -> V_93 ) ;
if ( F_26 ( V_94 ) )
return F_27 ( V_94 ) ;
V_84 = F_28 ( V_50 , 0 , 1 ) ;
if ( V_84 )
F_19 ( V_85 L_12 ) ;
else
V_84 = F_29 ( V_50 , F_30 ( V_50 , 2 ) , V_94 , V_87 -> V_93 , & V_89 , 6000 ) ;
F_31 ( V_94 ) ;
}
if ( V_84 )
return V_84 ;
if ( V_87 -> V_95 == 1 ) {
F_32 ( 250 ) ;
V_84 = F_33 ( V_88 ) ;
if ( V_84 ) {
F_19 ( V_85 L_13 ) ;
return V_84 ;
}
V_84 = F_34 ( V_88 ) ;
if ( V_84 ) {
F_19 ( V_85 L_14 ) ;
return V_84 ;
}
V_84 = F_18 ( V_15 -> V_62 ) ;
if ( V_84 ) {
F_19 ( V_85 L_15 , V_84 ) ;
F_35 ( V_15 -> V_62 ) ;
return V_84 ;
}
V_88 -> V_22 |= V_23 ;
F_2 ( L_16 , V_15 -> V_90 ) ;
}
return V_84 ;
}
int F_36 ( struct V_61 * V_62 , struct V_79 * V_96 )
{
int V_84 ;
struct V_14 * V_15 ;
if ( ( V_84 = F_37 ( V_62 , V_97 , 0 , & V_15 ) ) < 0 )
return V_84 ;
V_15 -> V_81 = V_98 ;
V_15 -> V_21 = F_15 ( V_62 ) ;
V_15 -> V_99 . V_100 = F_12 ;
V_15 -> V_99 . V_101 = F_23 ;
V_15 -> V_99 . V_102 = F_5 ;
V_15 -> V_99 . V_103 = F_10 ;
V_15 -> V_104 = 1 ;
sprintf ( V_15 -> V_90 , L_17 , V_96 -> V_105 -> V_106 , V_96 -> V_107 ) ;
return 0 ;
}
