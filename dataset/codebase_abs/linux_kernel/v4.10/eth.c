int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned short type ,
const void * V_5 , const void * V_6 , unsigned int V_7 )
{
struct V_8 * V_9 = (struct V_8 * ) F_2 ( V_2 , V_10 ) ;
if ( type != V_11 && type != V_12 )
V_9 -> V_13 = F_3 ( type ) ;
else
V_9 -> V_13 = F_3 ( V_7 ) ;
if ( ! V_6 )
V_6 = V_4 -> V_14 ;
memcpy ( V_9 -> V_15 , V_6 , V_16 ) ;
if ( V_5 ) {
memcpy ( V_9 -> V_17 , V_5 , V_16 ) ;
return V_10 ;
}
if ( V_4 -> V_18 & ( V_19 | V_20 ) ) {
F_4 ( V_9 -> V_17 ) ;
return V_10 ;
}
return - V_10 ;
}
T_1 F_5 ( void * V_21 , unsigned int V_7 )
{
const unsigned int V_18 = V_22 ;
const struct V_8 * V_9 = ( const struct V_8 * ) V_21 ;
struct V_23 V_24 ;
if ( F_6 ( V_7 < sizeof( * V_9 ) ) )
return V_7 ;
if ( ! F_7 ( & V_24 , V_21 , V_9 -> V_13 ,
sizeof( * V_9 ) , V_7 , V_18 ) )
return F_8 ( T_1 , V_24 . V_25 . V_26 , sizeof( * V_9 ) ) ;
return F_9 ( T_1 , F_10 ( NULL , V_21 , & V_24 , V_7 ) , V_7 ) ;
}
T_2 F_11 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
unsigned short V_27 ;
const unsigned short * V_28 ;
const struct V_8 * V_9 ;
V_2 -> V_4 = V_4 ;
F_12 ( V_2 ) ;
V_9 = (struct V_8 * ) V_2 -> V_21 ;
F_13 ( V_2 , V_10 ) ;
if ( F_6 ( F_14 ( V_9 -> V_17 ) ) ) {
if ( F_15 ( V_9 -> V_17 , V_4 -> V_29 ) )
V_2 -> V_30 = V_31 ;
else
V_2 -> V_30 = V_32 ;
}
else if ( F_6 ( ! F_15 ( V_9 -> V_17 ,
V_4 -> V_14 ) ) )
V_2 -> V_30 = V_33 ;
if ( F_6 ( F_16 ( V_4 ) ) )
return F_3 ( V_34 ) ;
if ( F_17 ( F_18 ( V_9 -> V_13 ) ) )
return V_9 -> V_13 ;
V_28 = F_19 ( V_2 , 0 , sizeof( * V_28 ) , & V_27 ) ;
if ( V_28 && * V_28 == 0xFFFF )
return F_3 ( V_11 ) ;
return F_3 ( V_12 ) ;
}
int F_20 ( const struct V_1 * V_2 , unsigned char * V_35 )
{
const struct V_8 * V_9 = F_21 ( V_2 ) ;
memcpy ( V_35 , V_9 -> V_15 , V_16 ) ;
return V_16 ;
}
int F_22 ( const struct V_36 * V_37 , struct V_38 * V_39 , T_2 type )
{
struct V_8 * V_9 ;
const struct V_3 * V_4 = V_37 -> V_4 ;
V_9 = (struct V_8 * )
( ( ( V_40 * ) V_39 -> V_41 ) + ( F_23 ( sizeof( * V_9 ) ) ) ) ;
if ( type == F_3 ( V_11 ) )
return - 1 ;
V_9 -> V_13 = type ;
memcpy ( V_9 -> V_15 , V_4 -> V_14 , V_16 ) ;
memcpy ( V_9 -> V_17 , V_37 -> V_42 , V_16 ) ;
V_39 -> V_43 = V_10 ;
return 0 ;
}
void F_24 ( struct V_38 * V_39 ,
const struct V_3 * V_4 ,
const unsigned char * V_35 )
{
memcpy ( ( ( V_40 * ) V_39 -> V_41 ) + F_23 ( sizeof( struct V_8 ) ) ,
V_35 , V_16 ) ;
}
int F_25 ( struct V_3 * V_4 , void * V_44 )
{
struct V_45 * V_46 = V_44 ;
if ( ! ( V_4 -> V_47 & V_48 ) && F_26 ( V_4 ) )
return - V_49 ;
if ( ! F_27 ( V_46 -> V_50 ) )
return - V_51 ;
return 0 ;
}
void F_28 ( struct V_3 * V_4 , void * V_44 )
{
struct V_45 * V_46 = V_44 ;
memcpy ( V_4 -> V_14 , V_46 -> V_50 , V_16 ) ;
}
int F_29 ( struct V_3 * V_4 , void * V_44 )
{
int V_52 ;
V_52 = F_25 ( V_4 , V_44 ) ;
if ( V_52 < 0 )
return V_52 ;
F_28 ( V_4 , V_44 ) ;
return 0 ;
}
int F_30 ( struct V_3 * V_4 , int V_53 )
{
F_31 ( V_4 , L_1 , V_54 ) ;
V_4 -> V_55 = V_53 ;
return 0 ;
}
int F_32 ( struct V_3 * V_4 )
{
if ( ! F_27 ( V_4 -> V_14 ) )
return - V_51 ;
return 0 ;
}
void F_33 ( struct V_3 * V_4 )
{
V_4 -> V_56 = & V_57 ;
V_4 -> type = V_58 ;
V_4 -> V_59 = V_10 ;
V_4 -> V_60 = V_10 ;
V_4 -> V_55 = V_61 ;
V_4 -> V_62 = V_63 ;
V_4 -> V_64 = V_61 ;
V_4 -> V_65 = V_16 ;
V_4 -> V_66 = V_67 ;
V_4 -> V_18 = V_68 | V_69 ;
V_4 -> V_47 |= V_70 ;
F_34 ( V_4 -> V_29 ) ;
}
struct V_3 * F_35 ( int V_71 , unsigned int V_72 ,
unsigned int V_73 )
{
return F_36 ( V_71 , L_2 , V_74 ,
F_33 , V_72 , V_73 ) ;
}
T_3 F_37 ( char * V_75 , const unsigned char * V_46 , int V_7 )
{
return F_38 ( V_75 , V_76 , L_3 , V_7 , V_46 ) ;
}
struct V_1 * * F_39 ( struct V_1 * * V_77 ,
struct V_1 * V_2 )
{
struct V_1 * V_44 , * * V_78 = NULL ;
struct V_8 * V_79 , * V_80 ;
unsigned int V_81 , V_82 ;
const struct V_83 * V_84 ;
T_2 type ;
int V_85 = 1 ;
V_82 = F_40 ( V_2 ) ;
V_81 = V_82 + sizeof( * V_79 ) ;
V_79 = F_41 ( V_2 , V_82 ) ;
if ( F_42 ( V_2 , V_81 ) ) {
V_79 = F_43 ( V_2 , V_81 , V_82 ) ;
if ( F_6 ( ! V_79 ) )
goto V_86;
}
V_85 = 0 ;
for ( V_44 = * V_77 ; V_44 ; V_44 = V_44 -> V_87 ) {
if ( ! F_44 ( V_44 ) -> V_88 )
continue;
V_80 = (struct V_8 * ) ( V_44 -> V_21 + V_82 ) ;
if ( F_45 ( V_79 , V_80 ) ) {
F_44 ( V_44 ) -> V_88 = 0 ;
continue;
}
}
type = V_79 -> V_13 ;
F_46 () ;
V_84 = F_47 ( type ) ;
if ( V_84 == NULL ) {
V_85 = 1 ;
goto V_89;
}
F_48 ( V_2 , sizeof( * V_79 ) ) ;
F_49 ( V_2 , V_79 , sizeof( * V_79 ) ) ;
V_78 = F_50 ( V_84 -> V_90 . V_91 , V_77 , V_2 ) ;
V_89:
F_51 () ;
V_86:
F_44 ( V_2 ) -> V_85 |= V_85 ;
return V_78 ;
}
int F_52 ( struct V_1 * V_2 , int V_92 )
{
struct V_8 * V_79 = (struct V_8 * ) ( V_2 -> V_21 + V_92 ) ;
T_2 type = V_79 -> V_13 ;
struct V_83 * V_84 ;
int V_93 = - V_94 ;
if ( V_2 -> V_95 )
F_53 ( V_2 , V_92 ) ;
F_46 () ;
V_84 = F_54 ( type ) ;
if ( V_84 != NULL )
V_93 = V_84 -> V_90 . V_96 ( V_2 , V_92 +
sizeof( struct V_8 ) ) ;
F_51 () ;
return V_93 ;
}
static int T_4 F_55 ( void )
{
F_56 ( & V_97 ) ;
return 0 ;
}
unsigned char * __weak F_57 ( void )
{
return NULL ;
}
int F_58 ( struct V_98 * V_4 , V_40 * V_99 )
{
const unsigned char * V_46 ;
struct V_100 * V_101 ;
if ( F_59 ( V_4 ) )
V_101 = F_60 ( F_61 ( V_4 ) ) ;
else
V_101 = V_4 -> V_102 ;
V_46 = NULL ;
if ( V_101 )
V_46 = F_62 ( V_101 ) ;
if ( ! V_46 )
V_46 = F_57 () ;
if ( ! V_46 )
return - V_103 ;
F_63 ( V_99 , V_46 ) ;
return 0 ;
}
