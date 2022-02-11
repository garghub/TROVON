static int F_1 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
struct V_3 * V_4 ;
F_2 ( & V_5 ) ;
F_3 ( & V_6 ) ;
V_4 = V_7 [ F_4 ( V_1 ) ] ;
if ( V_4 && V_4 -> V_8 ) {
int V_9 = 0 ;
const struct V_10 * V_11 ;
V_11 = F_5 ( V_4 -> V_8 ) ;
if ( ! V_11 )
goto V_12;
V_2 -> V_13 = V_4 ;
F_6 ( V_2 , V_11 ) ;
if ( V_2 -> V_14 -> V_15 )
V_9 = V_2 -> V_14 -> V_15 ( V_1 , V_2 ) ;
F_7 ( & V_6 ) ;
F_8 ( & V_5 ) ;
return V_9 ;
}
V_12:
F_7 ( & V_6 ) ;
F_8 ( & V_5 ) ;
return - V_16 ;
}
int F_9 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_13 ;
if ( ! V_4 )
return - V_16 ;
if ( ! V_4 -> V_17 )
return - V_18 ;
if ( ( V_2 -> V_19 & V_20 ) == V_21 ) {
if ( ! V_4 -> V_22 )
return - V_18 ;
V_4 -> V_22 -- ;
} else {
if ( ! V_4 -> V_23 )
return - V_18 ;
V_4 -> V_23 -- ;
}
V_4 -> V_17 -- ;
return 0 ;
}
int F_10 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_13 ;
if ( ! V_4 )
return - V_16 ;
if ( ( V_2 -> V_19 & V_20 ) == V_21 ) {
V_4 -> V_22 ++ ;
} else {
V_4 -> V_23 ++ ;
}
V_4 -> V_17 ++ ;
return 0 ;
}
long F_11 ( struct V_2 * V_2 ,
unsigned int V_24 , unsigned long V_25 )
{
struct V_3 * V_4 = V_2 -> V_13 ;
if ( ! V_4 )
return - V_16 ;
if ( ! V_4 -> V_26 )
return - V_27 ;
return F_12 ( V_2 , V_24 , V_25 , V_4 -> V_26 ) ;
}
static int F_13 ( struct V_28 * V_29 , int type )
{
T_1 V_30 = 0 ;
while ( V_30 < V_31 ) {
struct V_3 * V_32 ;
F_14 (dev, &adap->device_list, list_head)
if ( V_32 -> type == type && V_32 -> V_30 == V_30 )
goto V_33;
return V_30 ;
V_33:
V_30 ++ ;
}
return - V_34 ;
}
static void F_15 ( struct V_3 * V_4 ,
int type , int V_35 )
{
#if F_16 ( V_36 )
int V_37 = 0 , V_38 ;
if ( ! V_4 -> V_39 -> V_40 )
return;
V_4 -> V_41 = F_17 ( sizeof( * V_4 -> V_41 ) , V_42 ) ;
if ( ! V_4 -> V_41 )
return;
V_4 -> V_41 -> V_43 . V_32 . V_44 = V_45 ;
V_4 -> V_41 -> V_43 . V_32 . V_35 = V_35 ;
V_4 -> V_41 -> V_46 = V_4 -> V_46 ;
switch ( type ) {
case V_47 :
case V_48 :
case V_49 :
V_38 = 2 ;
break;
case V_50 :
V_38 = 0 ;
break;
default:
V_38 = 1 ;
}
if ( V_38 ) {
V_4 -> V_51 = F_18 ( V_38 , sizeof( * V_4 -> V_51 ) ,
V_42 ) ;
if ( ! V_4 -> V_51 ) {
F_19 ( V_4 -> V_41 ) ;
return;
}
}
switch ( type ) {
case V_49 :
V_4 -> V_41 -> type = V_52 ;
V_4 -> V_51 [ 0 ] . V_53 = V_54 ;
V_4 -> V_51 [ 1 ] . V_53 = V_55 ;
break;
case V_48 :
V_4 -> V_41 -> type = V_56 ;
V_4 -> V_51 [ 0 ] . V_53 = V_54 ;
V_4 -> V_51 [ 1 ] . V_53 = V_55 ;
break;
case V_57 :
V_4 -> V_41 -> type = V_58 ;
V_4 -> V_51 [ 0 ] . V_53 = V_54 ;
break;
case V_47 :
V_4 -> V_41 -> type = V_59 ;
V_4 -> V_51 [ 0 ] . V_53 = V_54 ;
V_4 -> V_51 [ 1 ] . V_53 = V_55 ;
break;
case V_50 :
V_4 -> V_41 -> type = V_60 ;
break;
default:
F_19 ( V_4 -> V_41 ) ;
V_4 -> V_41 = NULL ;
return;
}
if ( V_38 )
V_37 = F_20 ( V_4 -> V_41 , V_38 , V_4 -> V_51 , 0 ) ;
if ( ! V_37 )
V_37 = F_21 ( V_4 -> V_39 -> V_40 ,
V_4 -> V_41 ) ;
if ( V_37 < 0 ) {
F_22 ( V_61
L_1 ,
V_62 , V_4 -> V_41 -> V_46 ) ;
F_19 ( V_4 -> V_51 ) ;
F_19 ( V_4 -> V_41 ) ;
V_4 -> V_41 = NULL ;
return;
}
F_22 ( V_63 L_2 ,
V_62 , V_4 -> V_41 -> V_46 ) ;
#endif
}
int F_23 ( struct V_28 * V_29 , struct V_3 * * V_64 ,
const struct V_3 * V_65 , void * V_66 , int type )
{
struct V_3 * V_4 ;
struct V_10 * V_67 ;
struct V_68 * V_69 ;
int V_35 ;
int V_30 ;
F_2 ( & V_70 ) ;
if ( ( V_30 = F_13 ( V_29 , type ) ) < 0 ) {
F_8 ( & V_70 ) ;
* V_64 = NULL ;
F_22 ( V_61 L_3 , V_62 ) ;
return - V_34 ;
}
* V_64 = V_4 = F_24 ( sizeof( struct V_3 ) , V_42 ) ;
if ( ! V_4 ) {
F_8 ( & V_70 ) ;
return - V_71 ;
}
V_67 = F_17 ( sizeof( struct V_10 ) , V_42 ) ;
if ( ! V_67 ) {
F_19 ( V_4 ) ;
F_8 ( & V_70 ) ;
return - V_71 ;
}
memcpy ( V_4 , V_65 , sizeof( struct V_3 ) ) ;
V_4 -> type = type ;
V_4 -> V_30 = V_30 ;
V_4 -> V_39 = V_29 ;
V_4 -> V_66 = V_66 ;
V_4 -> V_8 = V_67 ;
F_25 ( & V_4 -> V_72 ) ;
memcpy ( V_67 , V_65 -> V_8 , sizeof( struct V_10 ) ) ;
V_67 -> V_73 = V_29 -> V_74 ;
F_26 ( & V_4 -> V_75 , & V_29 -> V_76 ) ;
F_27 ( & V_6 ) ;
#ifdef F_28
for ( V_35 = 0 ; V_35 < V_77 ; V_35 ++ )
if ( V_7 [ V_35 ] == NULL )
break;
if ( V_35 == V_77 ) {
F_19 ( V_67 ) ;
F_19 ( V_4 ) ;
F_29 ( & V_6 ) ;
F_8 ( & V_70 ) ;
return - V_27 ;
}
#else
V_35 = F_30 ( V_29 -> V_78 , type , V_30 ) ;
#endif
V_4 -> V_35 = V_35 ;
V_7 [ V_35 ] = V_4 ;
F_29 ( & V_6 ) ;
F_8 ( & V_70 ) ;
V_69 = F_31 ( V_79 , V_29 -> V_68 ,
F_32 ( V_45 , V_35 ) ,
V_4 , L_4 , V_29 -> V_78 , V_80 [ type ] , V_30 ) ;
if ( F_33 ( V_69 ) ) {
F_22 ( V_61 L_5 ,
V_62 , V_29 -> V_78 , V_80 [ type ] , V_30 , F_34 ( V_69 ) ) ;
return F_34 ( V_69 ) ;
}
F_35 ( V_63 L_6 ,
V_29 -> V_78 , V_80 [ type ] , V_30 , V_35 , V_35 ) ;
F_15 ( V_4 , type , V_35 ) ;
return 0 ;
}
void F_36 ( struct V_3 * V_4 )
{
if ( ! V_4 )
return;
F_27 ( & V_6 ) ;
V_7 [ V_4 -> V_35 ] = NULL ;
F_29 ( & V_6 ) ;
F_37 ( V_79 , F_32 ( V_45 , V_4 -> V_35 ) ) ;
#if F_16 ( V_36 )
if ( V_4 -> V_41 ) {
F_38 ( V_4 -> V_41 ) ;
F_19 ( V_4 -> V_41 ) ;
F_19 ( V_4 -> V_51 ) ;
}
#endif
F_39 ( & V_4 -> V_75 ) ;
F_19 ( V_4 -> V_8 ) ;
F_19 ( V_4 ) ;
}
void F_40 ( struct V_28 * V_29 )
{
struct V_81 * V_40 = V_29 -> V_40 ;
struct V_82 * V_41 , * V_83 = NULL , * V_84 = NULL ;
struct V_82 * V_85 = NULL , * V_86 = NULL , * V_87 = NULL ;
if ( ! V_40 )
return;
F_41 (entity, mdev) {
switch ( V_41 -> type ) {
case V_88 :
V_83 = V_41 ;
break;
case V_52 :
V_84 = V_41 ;
break;
case V_56 :
V_85 = V_41 ;
break;
case V_58 :
V_86 = V_41 ;
break;
case V_59 :
V_87 = V_41 ;
break;
}
}
if ( V_83 && V_84 )
F_42 ( V_83 , 0 , V_84 , 0 , 0 ) ;
if ( V_84 && V_85 )
F_42 ( V_84 , 1 , V_85 , 0 , V_89 ) ;
if ( V_85 && V_86 )
F_42 ( V_85 , 1 , V_86 , 0 , V_89 ) ;
if ( V_85 && V_87 )
F_42 ( V_85 , 1 , V_87 , 0 , V_89 ) ;
}
static int F_43 ( int V_78 )
{
struct V_75 * V_90 ;
F_44 (entry, &dvb_adapter_list) {
struct V_28 * V_29 ;
V_29 = F_45 ( V_90 , struct V_28 , V_75 ) ;
if ( V_29 -> V_78 == V_78 )
return 0 ;
}
return 1 ;
}
static int F_46 ( void )
{
int V_78 = 0 ;
while ( V_78 < V_91 ) {
if ( F_43 ( V_78 ) )
return V_78 ;
V_78 ++ ;
}
return - V_34 ;
}
int F_47 ( struct V_28 * V_29 , const char * V_46 ,
struct V_74 * V_74 , struct V_68 * V_68 ,
short * V_92 )
{
int V_93 , V_78 ;
F_2 ( & V_70 ) ;
for ( V_93 = 0 ; V_93 < V_91 ; ++ V_93 ) {
V_78 = V_92 [ V_93 ] ;
if ( V_78 >= 0 && V_78 < V_91 ) {
if ( F_43 ( V_78 ) )
break;
} else {
V_78 = F_46 () ;
break;
}
V_78 = - 1 ;
}
if ( V_78 < 0 ) {
F_8 ( & V_70 ) ;
return - V_34 ;
}
memset ( V_29 , 0 , sizeof( struct V_28 ) ) ;
F_48 ( & V_29 -> V_76 ) ;
F_22 ( V_94 L_7 , V_46 ) ;
V_29 -> V_78 = V_78 ;
V_29 -> V_46 = V_46 ;
V_29 -> V_74 = V_74 ;
V_29 -> V_68 = V_68 ;
V_29 -> V_95 = 0 ;
V_29 -> V_96 = NULL ;
F_49 ( & V_29 -> V_97 ) ;
F_26 ( & V_29 -> V_75 , & V_98 ) ;
F_8 ( & V_70 ) ;
return V_78 ;
}
int F_50 ( struct V_28 * V_29 )
{
F_2 ( & V_70 ) ;
F_39 ( & V_29 -> V_75 ) ;
F_8 ( & V_70 ) ;
return 0 ;
}
int F_12 ( struct V_2 * V_2 ,
unsigned int V_24 , unsigned long V_25 ,
int (* F_51)( struct V_2 * V_2 ,
unsigned int V_24 , void * V_25 ) )
{
char V_99 [ 128 ] ;
void * V_100 = NULL ;
void * V_101 = NULL ;
int V_9 = - V_27 ;
switch ( F_52 ( V_24 ) ) {
case V_102 :
V_101 = ( void * ) V_25 ;
break;
case V_103 :
case V_104 :
case ( V_104 | V_103 ) :
if ( F_53 ( V_24 ) <= sizeof( V_99 ) ) {
V_101 = V_99 ;
} else {
V_100 = F_24 ( F_53 ( V_24 ) , V_42 ) ;
if ( NULL == V_100 )
return - V_71 ;
V_101 = V_100 ;
}
V_9 = - V_105 ;
if ( F_54 ( V_101 , ( void V_106 * ) V_25 , F_53 ( V_24 ) ) )
goto V_107;
break;
}
if ( ( V_9 = F_51 ( V_2 , V_24 , V_101 ) ) == - V_108 )
V_9 = - V_109 ;
if ( V_9 < 0 )
goto V_107;
switch ( F_52 ( V_24 ) )
{
case V_103 :
case ( V_104 | V_103 ) :
if ( F_55 ( ( void V_106 * ) V_25 , V_101 , F_53 ( V_24 ) ) )
V_9 = - V_105 ;
break;
}
V_107:
F_19 ( V_100 ) ;
return V_9 ;
}
static int F_56 ( struct V_68 * V_32 , struct V_110 * V_111 )
{
struct V_3 * V_4 = F_57 ( V_32 ) ;
F_58 ( V_111 , L_8 , V_4 -> V_39 -> V_78 ) ;
F_58 ( V_111 , L_9 , V_80 [ V_4 -> type ] ) ;
F_58 ( V_111 , L_10 , V_4 -> V_30 ) ;
return 0 ;
}
static char * F_59 ( struct V_68 * V_32 , T_2 * V_112 )
{
struct V_3 * V_4 = F_57 ( V_32 ) ;
return F_60 ( V_42 , L_11 ,
V_4 -> V_39 -> V_78 , V_80 [ V_4 -> type ] , V_4 -> V_30 ) ;
}
static int T_3 F_61 ( void )
{
int V_113 ;
T_4 V_32 = F_32 ( V_45 , 0 ) ;
if ( ( V_113 = F_62 ( V_32 , V_77 , L_12 ) ) != 0 ) {
F_22 ( V_61 L_13 , V_45 ) ;
return V_113 ;
}
F_63 ( & V_114 , & V_115 ) ;
if ( ( V_113 = F_64 ( & V_114 , V_32 , V_77 ) ) != 0 ) {
F_22 ( V_61 L_14 ) ;
goto error;
}
V_79 = F_65 ( V_116 , L_15 ) ;
if ( F_33 ( V_79 ) ) {
V_113 = F_34 ( V_79 ) ;
goto error;
}
V_79 -> V_117 = F_56 ;
V_79 -> V_118 = F_59 ;
return 0 ;
error:
F_66 ( & V_114 ) ;
F_67 ( V_32 , V_77 ) ;
return V_113 ;
}
static void T_5 F_68 ( void )
{
F_69 ( V_79 ) ;
F_66 ( & V_114 ) ;
F_67 ( F_32 ( V_45 , 0 ) , V_77 ) ;
}
