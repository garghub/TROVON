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
if ( V_53 < 68 || V_53 > V_54 )
return - V_55 ;
V_4 -> V_56 = V_53 ;
return 0 ;
}
int F_31 ( struct V_3 * V_4 )
{
if ( ! F_27 ( V_4 -> V_14 ) )
return - V_51 ;
return 0 ;
}
void F_32 ( struct V_3 * V_4 )
{
V_4 -> V_57 = & V_58 ;
V_4 -> type = V_59 ;
V_4 -> V_60 = V_10 ;
V_4 -> V_56 = V_54 ;
V_4 -> V_61 = V_16 ;
V_4 -> V_62 = 1000 ;
V_4 -> V_18 = V_63 | V_64 ;
V_4 -> V_47 |= V_65 ;
F_33 ( V_4 -> V_29 ) ;
}
struct V_3 * F_34 ( int V_66 , unsigned int V_67 ,
unsigned int V_68 )
{
return F_35 ( V_66 , L_1 , V_69 ,
F_32 , V_67 , V_68 ) ;
}
T_3 F_36 ( char * V_70 , const unsigned char * V_46 , int V_7 )
{
return F_37 ( V_70 , V_71 , L_2 , V_7 , V_46 ) ;
}
struct V_1 * * F_38 ( struct V_1 * * V_72 ,
struct V_1 * V_2 )
{
struct V_1 * V_44 , * * V_73 = NULL ;
struct V_8 * V_74 , * V_75 ;
unsigned int V_76 , V_77 ;
const struct V_78 * V_79 ;
T_2 type ;
int V_80 = 1 ;
V_77 = F_39 ( V_2 ) ;
V_76 = V_77 + sizeof( * V_74 ) ;
V_74 = F_40 ( V_2 , V_77 ) ;
if ( F_41 ( V_2 , V_76 ) ) {
V_74 = F_42 ( V_2 , V_76 , V_77 ) ;
if ( F_6 ( ! V_74 ) )
goto V_81;
}
V_80 = 0 ;
for ( V_44 = * V_72 ; V_44 ; V_44 = V_44 -> V_82 ) {
if ( ! F_43 ( V_44 ) -> V_83 )
continue;
V_75 = (struct V_8 * ) ( V_44 -> V_21 + V_77 ) ;
if ( F_44 ( V_74 , V_75 ) ) {
F_43 ( V_44 ) -> V_83 = 0 ;
continue;
}
}
type = V_74 -> V_13 ;
F_45 () ;
V_79 = F_46 ( type ) ;
if ( V_79 == NULL ) {
V_80 = 1 ;
goto V_84;
}
F_47 ( V_2 , sizeof( * V_74 ) ) ;
F_48 ( V_2 , V_74 , sizeof( * V_74 ) ) ;
V_73 = F_49 ( V_79 -> V_85 . V_86 , V_72 , V_2 ) ;
V_84:
F_50 () ;
V_81:
F_43 ( V_2 ) -> V_80 |= V_80 ;
return V_73 ;
}
int F_51 ( struct V_1 * V_2 , int V_87 )
{
struct V_8 * V_74 = (struct V_8 * ) ( V_2 -> V_21 + V_87 ) ;
T_2 type = V_74 -> V_13 ;
struct V_78 * V_79 ;
int V_88 = - V_89 ;
if ( V_2 -> V_90 )
F_52 ( V_2 , V_87 ) ;
F_45 () ;
V_79 = F_53 ( type ) ;
if ( V_79 != NULL )
V_88 = V_79 -> V_85 . V_91 ( V_2 , V_87 +
sizeof( struct V_8 ) ) ;
F_50 () ;
return V_88 ;
}
static int T_4 F_54 ( void )
{
F_55 ( & V_92 ) ;
return 0 ;
}
unsigned char * __weak F_56 ( void )
{
return NULL ;
}
int F_57 ( struct V_93 * V_4 , V_40 * V_94 )
{
const unsigned char * V_46 ;
struct V_95 * V_96 ;
if ( F_58 ( V_4 ) )
V_96 = F_59 ( F_60 ( V_4 ) ) ;
else
V_96 = V_4 -> V_97 ;
V_46 = NULL ;
if ( V_96 )
V_46 = F_61 ( V_96 ) ;
if ( ! V_46 )
V_46 = F_56 () ;
if ( ! V_46 )
return - V_98 ;
F_62 ( V_94 , V_46 ) ;
return 0 ;
}
