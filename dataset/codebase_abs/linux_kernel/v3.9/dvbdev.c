static int F_1 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
struct V_3 * V_4 ;
F_2 ( & V_5 ) ;
F_3 ( & V_6 ) ;
V_4 = V_7 [ F_4 ( V_1 ) ] ;
if ( V_4 && V_4 -> V_8 ) {
int V_9 = 0 ;
const struct V_10 * V_11 ;
V_2 -> V_12 = V_4 ;
V_11 = V_2 -> V_13 ;
V_2 -> V_13 = F_5 ( V_4 -> V_8 ) ;
if ( V_2 -> V_13 == NULL ) {
V_2 -> V_13 = V_11 ;
goto V_14;
}
if( V_2 -> V_13 -> V_15 )
V_9 = V_2 -> V_13 -> V_15 ( V_1 , V_2 ) ;
if ( V_9 ) {
F_6 ( V_2 -> V_13 ) ;
V_2 -> V_13 = F_5 ( V_11 ) ;
}
F_6 ( V_11 ) ;
F_7 ( & V_6 ) ;
F_8 ( & V_5 ) ;
return V_9 ;
}
V_14:
F_7 ( & V_6 ) ;
F_8 ( & V_5 ) ;
return - V_16 ;
}
int F_9 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_12 ;
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
struct V_3 * V_4 = V_2 -> V_12 ;
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
struct V_3 * V_4 = V_2 -> V_12 ;
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
int F_15 ( struct V_28 * V_29 , struct V_3 * * V_35 ,
const struct V_3 * V_36 , void * V_37 , int type )
{
struct V_3 * V_4 ;
struct V_10 * V_38 ;
struct V_39 * V_40 ;
int V_41 ;
int V_30 ;
F_2 ( & V_42 ) ;
if ( ( V_30 = F_13 ( V_29 , type ) ) < 0 ) {
F_8 ( & V_42 ) ;
* V_35 = NULL ;
F_16 ( V_43 L_1 , V_44 ) ;
return - V_34 ;
}
* V_35 = V_4 = F_17 ( sizeof( struct V_3 ) , V_45 ) ;
if ( ! V_4 ) {
F_8 ( & V_42 ) ;
return - V_46 ;
}
V_38 = F_18 ( sizeof( struct V_10 ) , V_45 ) ;
if ( ! V_38 ) {
F_19 ( V_4 ) ;
F_8 ( & V_42 ) ;
return - V_46 ;
}
memcpy ( V_4 , V_36 , sizeof( struct V_3 ) ) ;
V_4 -> type = type ;
V_4 -> V_30 = V_30 ;
V_4 -> V_47 = V_29 ;
V_4 -> V_37 = V_37 ;
V_4 -> V_8 = V_38 ;
F_20 ( & V_4 -> V_48 ) ;
memcpy ( V_38 , V_36 -> V_8 , sizeof( struct V_10 ) ) ;
V_38 -> V_49 = V_29 -> V_50 ;
F_21 ( & V_4 -> V_51 , & V_29 -> V_52 ) ;
F_22 ( & V_6 ) ;
#ifdef F_23
for ( V_41 = 0 ; V_41 < V_53 ; V_41 ++ )
if ( V_7 [ V_41 ] == NULL )
break;
if ( V_41 == V_53 ) {
F_19 ( V_38 ) ;
F_19 ( V_4 ) ;
F_24 ( & V_6 ) ;
F_8 ( & V_42 ) ;
return - V_27 ;
}
#else
V_41 = F_25 ( V_29 -> V_54 , type , V_30 ) ;
#endif
V_4 -> V_41 = V_41 ;
V_7 [ V_41 ] = V_4 ;
F_24 ( & V_6 ) ;
F_8 ( & V_42 ) ;
V_40 = F_26 ( V_55 , V_29 -> V_39 ,
F_27 ( V_56 , V_41 ) ,
V_4 , L_2 , V_29 -> V_54 , V_57 [ type ] , V_30 ) ;
if ( F_28 ( V_40 ) ) {
F_16 ( V_43 L_3 ,
V_44 , V_29 -> V_54 , V_57 [ type ] , V_30 , F_29 ( V_40 ) ) ;
return F_29 ( V_40 ) ;
}
F_30 ( V_58 L_4 ,
V_29 -> V_54 , V_57 [ type ] , V_30 , V_41 , V_41 ) ;
return 0 ;
}
void F_31 ( struct V_3 * V_4 )
{
if ( ! V_4 )
return;
F_22 ( & V_6 ) ;
V_7 [ V_4 -> V_41 ] = NULL ;
F_24 ( & V_6 ) ;
F_32 ( V_55 , F_27 ( V_56 , V_4 -> V_41 ) ) ;
F_33 ( & V_4 -> V_51 ) ;
F_19 ( V_4 -> V_8 ) ;
F_19 ( V_4 ) ;
}
static int F_34 ( int V_54 )
{
struct V_51 * V_59 ;
F_35 (entry, &dvb_adapter_list) {
struct V_28 * V_29 ;
V_29 = F_36 ( V_59 , struct V_28 , V_51 ) ;
if ( V_29 -> V_54 == V_54 )
return 0 ;
}
return 1 ;
}
static int F_37 ( void )
{
int V_54 = 0 ;
while ( V_54 < V_60 ) {
if ( F_34 ( V_54 ) )
return V_54 ;
V_54 ++ ;
}
return - V_34 ;
}
int F_38 ( struct V_28 * V_29 , const char * V_61 ,
struct V_50 * V_50 , struct V_39 * V_39 ,
short * V_62 )
{
int V_63 , V_54 ;
F_2 ( & V_42 ) ;
for ( V_63 = 0 ; V_63 < V_60 ; ++ V_63 ) {
V_54 = V_62 [ V_63 ] ;
if ( V_54 >= 0 && V_54 < V_60 ) {
if ( F_34 ( V_54 ) )
break;
} else {
V_54 = F_37 () ;
break;
}
V_54 = - 1 ;
}
if ( V_54 < 0 ) {
F_8 ( & V_42 ) ;
return - V_34 ;
}
memset ( V_29 , 0 , sizeof( struct V_28 ) ) ;
F_39 ( & V_29 -> V_52 ) ;
F_16 ( V_64 L_5 , V_61 ) ;
V_29 -> V_54 = V_54 ;
V_29 -> V_61 = V_61 ;
V_29 -> V_50 = V_50 ;
V_29 -> V_39 = V_39 ;
V_29 -> V_65 = 0 ;
V_29 -> V_66 = NULL ;
F_40 ( & V_29 -> V_67 ) ;
F_21 ( & V_29 -> V_51 , & V_68 ) ;
F_8 ( & V_42 ) ;
return V_54 ;
}
int F_41 ( struct V_28 * V_29 )
{
F_2 ( & V_42 ) ;
F_33 ( & V_29 -> V_51 ) ;
F_8 ( & V_42 ) ;
return 0 ;
}
int F_12 ( struct V_2 * V_2 ,
unsigned int V_24 , unsigned long V_25 ,
int (* F_42)( struct V_2 * V_2 ,
unsigned int V_24 , void * V_25 ) )
{
char V_69 [ 128 ] ;
void * V_70 = NULL ;
void * V_71 = NULL ;
int V_9 = - V_27 ;
switch ( F_43 ( V_24 ) ) {
case V_72 :
V_71 = ( void * ) V_25 ;
break;
case V_73 :
case V_74 :
case ( V_74 | V_73 ) :
if ( F_44 ( V_24 ) <= sizeof( V_69 ) ) {
V_71 = V_69 ;
} else {
V_70 = F_17 ( F_44 ( V_24 ) , V_45 ) ;
if ( NULL == V_70 )
return - V_46 ;
V_71 = V_70 ;
}
V_9 = - V_75 ;
if ( F_45 ( V_71 , ( void V_76 * ) V_25 , F_44 ( V_24 ) ) )
goto V_77;
break;
}
if ( ( V_9 = F_42 ( V_2 , V_24 , V_71 ) ) == - V_78 )
V_9 = - V_79 ;
if ( V_9 < 0 )
goto V_77;
switch ( F_43 ( V_24 ) )
{
case V_73 :
case ( V_74 | V_73 ) :
if ( F_46 ( ( void V_76 * ) V_25 , V_71 , F_44 ( V_24 ) ) )
V_9 = - V_75 ;
break;
}
V_77:
F_19 ( V_70 ) ;
return V_9 ;
}
static int F_47 ( struct V_39 * V_32 , struct V_80 * V_81 )
{
struct V_3 * V_4 = F_48 ( V_32 ) ;
F_49 ( V_81 , L_6 , V_4 -> V_47 -> V_54 ) ;
F_49 ( V_81 , L_7 , V_57 [ V_4 -> type ] ) ;
F_49 ( V_81 , L_8 , V_4 -> V_30 ) ;
return 0 ;
}
static char * F_50 ( struct V_39 * V_32 , T_2 * V_82 )
{
struct V_3 * V_4 = F_48 ( V_32 ) ;
return F_51 ( V_45 , L_9 ,
V_4 -> V_47 -> V_54 , V_57 [ V_4 -> type ] , V_4 -> V_30 ) ;
}
static int T_3 F_52 ( void )
{
int V_83 ;
T_4 V_32 = F_27 ( V_56 , 0 ) ;
if ( ( V_83 = F_53 ( V_32 , V_53 , L_10 ) ) != 0 ) {
F_16 ( V_43 L_11 , V_56 ) ;
return V_83 ;
}
F_54 ( & V_84 , & V_85 ) ;
if ( ( V_83 = F_55 ( & V_84 , V_32 , V_53 ) ) != 0 ) {
F_16 ( V_43 L_12 ) ;
goto error;
}
V_55 = F_56 ( V_86 , L_13 ) ;
if ( F_28 ( V_55 ) ) {
V_83 = F_29 ( V_55 ) ;
goto error;
}
V_55 -> V_87 = F_47 ;
V_55 -> V_88 = F_50 ;
return 0 ;
error:
F_57 ( & V_84 ) ;
F_58 ( V_32 , V_53 ) ;
return V_83 ;
}
static void T_5 F_59 ( void )
{
F_60 ( V_55 ) ;
F_57 ( & V_84 ) ;
F_58 ( F_27 ( V_56 , 0 ) , V_53 ) ;
}
