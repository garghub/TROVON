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
const struct V_8 * V_9 = ( const struct V_8 * ) V_21 ;
struct V_22 V_23 ;
if ( V_7 < sizeof( * V_9 ) )
return V_7 ;
if ( ! F_6 ( & V_23 , V_21 , V_9 -> V_13 ,
sizeof( * V_9 ) , V_7 ) )
return F_7 ( T_1 , V_23 . V_24 . V_25 , sizeof( * V_9 ) ) ;
return F_8 ( T_1 , F_9 ( NULL , V_21 , & V_23 , V_7 ) , V_7 ) ;
}
T_2 F_10 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
unsigned short V_26 ;
const unsigned short * V_27 ;
const struct V_8 * V_9 ;
V_2 -> V_4 = V_4 ;
F_11 ( V_2 ) ;
V_9 = (struct V_8 * ) V_2 -> V_21 ;
F_12 ( V_2 , V_10 ) ;
if ( F_13 ( F_14 ( V_9 -> V_17 ) ) ) {
if ( F_15 ( V_9 -> V_17 , V_4 -> V_28 ) )
V_2 -> V_29 = V_30 ;
else
V_2 -> V_29 = V_31 ;
}
else if ( F_13 ( ! F_15 ( V_9 -> V_17 ,
V_4 -> V_14 ) ) )
V_2 -> V_29 = V_32 ;
if ( F_13 ( F_16 ( V_4 ) ) )
return F_3 ( V_33 ) ;
if ( F_17 ( F_18 ( V_9 -> V_13 ) ) )
return V_9 -> V_13 ;
V_27 = F_19 ( V_2 , 0 , sizeof( * V_27 ) , & V_26 ) ;
if ( V_27 && * V_27 == 0xFFFF )
return F_3 ( V_11 ) ;
return F_3 ( V_12 ) ;
}
int F_20 ( const struct V_1 * V_2 , unsigned char * V_34 )
{
const struct V_8 * V_9 = F_21 ( V_2 ) ;
memcpy ( V_34 , V_9 -> V_15 , V_16 ) ;
return V_16 ;
}
int F_22 ( const struct V_35 * V_36 , struct V_37 * V_38 , T_2 type )
{
struct V_8 * V_9 ;
const struct V_3 * V_4 = V_36 -> V_4 ;
V_9 = (struct V_8 * )
( ( ( V_39 * ) V_38 -> V_40 ) + ( F_23 ( sizeof( * V_9 ) ) ) ) ;
if ( type == F_3 ( V_11 ) )
return - 1 ;
V_9 -> V_13 = type ;
memcpy ( V_9 -> V_15 , V_4 -> V_14 , V_16 ) ;
memcpy ( V_9 -> V_17 , V_36 -> V_41 , V_16 ) ;
V_38 -> V_42 = V_10 ;
return 0 ;
}
void F_24 ( struct V_37 * V_38 ,
const struct V_3 * V_4 ,
const unsigned char * V_34 )
{
memcpy ( ( ( V_39 * ) V_38 -> V_40 ) + F_23 ( sizeof( struct V_8 ) ) ,
V_34 , V_16 ) ;
}
int F_25 ( struct V_3 * V_4 , void * V_43 )
{
struct V_44 * V_45 = V_43 ;
if ( ! ( V_4 -> V_46 & V_47 ) && F_26 ( V_4 ) )
return - V_48 ;
if ( ! F_27 ( V_45 -> V_49 ) )
return - V_50 ;
return 0 ;
}
void F_28 ( struct V_3 * V_4 , void * V_43 )
{
struct V_44 * V_45 = V_43 ;
memcpy ( V_4 -> V_14 , V_45 -> V_49 , V_16 ) ;
}
int F_29 ( struct V_3 * V_4 , void * V_43 )
{
int V_51 ;
V_51 = F_25 ( V_4 , V_43 ) ;
if ( V_51 < 0 )
return V_51 ;
F_28 ( V_4 , V_43 ) ;
return 0 ;
}
int F_30 ( struct V_3 * V_4 , int V_52 )
{
if ( V_52 < 68 || V_52 > V_53 )
return - V_54 ;
V_4 -> V_55 = V_52 ;
return 0 ;
}
int F_31 ( struct V_3 * V_4 )
{
if ( ! F_27 ( V_4 -> V_14 ) )
return - V_50 ;
return 0 ;
}
void F_32 ( struct V_3 * V_4 )
{
V_4 -> V_56 = & V_57 ;
V_4 -> type = V_58 ;
V_4 -> V_59 = V_10 ;
V_4 -> V_55 = V_53 ;
V_4 -> V_60 = V_16 ;
V_4 -> V_61 = 1000 ;
V_4 -> V_18 = V_62 | V_63 ;
V_4 -> V_46 |= V_64 ;
F_33 ( V_4 -> V_28 ) ;
}
struct V_3 * F_34 ( int V_65 , unsigned int V_66 ,
unsigned int V_67 )
{
return F_35 ( V_65 , L_1 , V_68 ,
F_32 , V_66 , V_67 ) ;
}
T_3 F_36 ( char * V_69 , const unsigned char * V_45 , int V_7 )
{
return F_37 ( V_69 , V_70 , L_2 , V_7 , V_45 ) ;
}
struct V_1 * * F_38 ( struct V_1 * * V_71 ,
struct V_1 * V_2 )
{
struct V_1 * V_43 , * * V_72 = NULL ;
struct V_8 * V_73 , * V_74 ;
unsigned int V_75 , V_76 ;
const struct V_77 * V_78 ;
T_2 type ;
int V_79 = 1 ;
V_76 = F_39 ( V_2 ) ;
V_75 = V_76 + sizeof( * V_73 ) ;
V_73 = F_40 ( V_2 , V_76 ) ;
if ( F_41 ( V_2 , V_75 ) ) {
V_73 = F_42 ( V_2 , V_75 , V_76 ) ;
if ( F_13 ( ! V_73 ) )
goto V_80;
}
V_79 = 0 ;
for ( V_43 = * V_71 ; V_43 ; V_43 = V_43 -> V_81 ) {
if ( ! F_43 ( V_43 ) -> V_82 )
continue;
V_74 = (struct V_8 * ) ( V_43 -> V_21 + V_76 ) ;
if ( F_44 ( V_73 , V_74 ) ) {
F_43 ( V_43 ) -> V_82 = 0 ;
continue;
}
}
type = V_73 -> V_13 ;
F_45 () ;
V_78 = F_46 ( type ) ;
if ( V_78 == NULL ) {
V_79 = 1 ;
goto V_83;
}
F_47 ( V_2 , sizeof( * V_73 ) ) ;
F_48 ( V_2 , V_73 , sizeof( * V_73 ) ) ;
V_72 = V_78 -> V_84 . V_85 ( V_71 , V_2 ) ;
V_83:
F_49 () ;
V_80:
F_43 ( V_2 ) -> V_79 |= V_79 ;
return V_72 ;
}
int F_50 ( struct V_1 * V_2 , int V_86 )
{
struct V_8 * V_73 = (struct V_8 * ) ( V_2 -> V_21 + V_86 ) ;
T_2 type = V_73 -> V_13 ;
struct V_77 * V_78 ;
int V_87 = - V_88 ;
if ( V_2 -> V_89 )
F_51 ( V_2 , V_86 ) ;
F_45 () ;
V_78 = F_52 ( type ) ;
if ( V_78 != NULL )
V_87 = V_78 -> V_84 . V_90 ( V_2 , V_86 +
sizeof( struct V_8 ) ) ;
F_49 () ;
return V_87 ;
}
static int T_4 F_53 ( void )
{
F_54 ( & V_91 ) ;
return 0 ;
}
