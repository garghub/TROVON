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
memset ( V_9 -> V_17 , 0 , V_16 ) ;
return V_10 ;
}
return - V_10 ;
}
int F_4 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = (struct V_8 * ) V_2 -> V_21 ;
struct V_3 * V_4 = V_2 -> V_4 ;
switch ( V_9 -> V_13 ) {
#ifdef F_5
case F_3 ( V_22 ) :
return F_6 ( V_9 -> V_17 , V_2 ) ;
#endif
default:
F_7 ( V_4 ,
L_1 ,
V_4 -> V_23 , F_8 ( V_9 -> V_13 ) ) ;
memcpy ( V_9 -> V_15 , V_4 -> V_14 , V_16 ) ;
break;
}
return 0 ;
}
T_1 F_9 ( void * V_21 , unsigned int V_7 )
{
const struct V_8 * V_9 = ( const struct V_8 * ) V_21 ;
struct V_24 V_25 ;
if ( V_7 < sizeof( * V_9 ) )
return V_7 ;
if ( ! F_10 ( NULL , & V_25 , V_21 ,
V_9 -> V_13 , sizeof( * V_9 ) , V_7 ) )
return F_11 ( T_1 , V_25 . V_26 , sizeof( * V_9 ) ) ;
return F_12 ( T_1 , F_13 ( NULL , V_21 , & V_25 , V_7 ) , V_7 ) ;
}
T_2 F_14 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
unsigned short V_27 ;
const unsigned short * V_28 ;
const struct V_8 * V_9 ;
V_2 -> V_4 = V_4 ;
F_15 ( V_2 ) ;
F_16 ( V_2 , V_10 ) ;
V_9 = F_17 ( V_2 ) ;
if ( F_18 ( F_19 ( V_9 -> V_17 ) ) ) {
if ( F_20 ( V_9 -> V_17 , V_4 -> V_29 ) )
V_2 -> V_30 = V_31 ;
else
V_2 -> V_30 = V_32 ;
}
else if ( F_18 ( ! F_20 ( V_9 -> V_17 ,
V_4 -> V_14 ) ) )
V_2 -> V_30 = V_33 ;
if ( F_18 ( F_21 ( V_4 ) ) )
return F_3 ( V_34 ) ;
if ( F_22 ( F_8 ( V_9 -> V_13 ) >= V_35 ) )
return V_9 -> V_13 ;
V_28 = F_23 ( V_2 , 0 , sizeof( * V_28 ) , & V_27 ) ;
if ( V_28 && * V_28 == 0xFFFF )
return F_3 ( V_11 ) ;
return F_3 ( V_12 ) ;
}
int F_24 ( const struct V_1 * V_2 , unsigned char * V_36 )
{
const struct V_8 * V_9 = F_17 ( V_2 ) ;
memcpy ( V_36 , V_9 -> V_15 , V_16 ) ;
return V_16 ;
}
int F_25 ( const struct V_37 * V_38 , struct V_39 * V_40 , T_2 type )
{
struct V_8 * V_9 ;
const struct V_3 * V_4 = V_38 -> V_4 ;
V_9 = (struct V_8 * )
( ( ( V_41 * ) V_40 -> V_42 ) + ( F_26 ( sizeof( * V_9 ) ) ) ) ;
if ( type == F_3 ( V_11 ) )
return - 1 ;
V_9 -> V_13 = type ;
memcpy ( V_9 -> V_15 , V_4 -> V_14 , V_16 ) ;
memcpy ( V_9 -> V_17 , V_38 -> V_43 , V_16 ) ;
V_40 -> V_44 = V_10 ;
return 0 ;
}
void F_27 ( struct V_39 * V_40 ,
const struct V_3 * V_4 ,
const unsigned char * V_36 )
{
memcpy ( ( ( V_41 * ) V_40 -> V_42 ) + F_26 ( sizeof( struct V_8 ) ) ,
V_36 , V_16 ) ;
}
int F_28 ( struct V_3 * V_4 , void * V_45 )
{
struct V_46 * V_47 = V_45 ;
if ( ! ( V_4 -> V_48 & V_49 ) && F_29 ( V_4 ) )
return - V_50 ;
if ( ! F_30 ( V_47 -> V_51 ) )
return - V_52 ;
return 0 ;
}
void F_31 ( struct V_3 * V_4 , void * V_45 )
{
struct V_46 * V_47 = V_45 ;
memcpy ( V_4 -> V_14 , V_47 -> V_51 , V_16 ) ;
}
int F_32 ( struct V_3 * V_4 , void * V_45 )
{
int V_53 ;
V_53 = F_28 ( V_4 , V_45 ) ;
if ( V_53 < 0 )
return V_53 ;
F_31 ( V_4 , V_45 ) ;
return 0 ;
}
int F_33 ( struct V_3 * V_4 , int V_54 )
{
if ( V_54 < 68 || V_54 > V_55 )
return - V_56 ;
V_4 -> V_57 = V_54 ;
return 0 ;
}
int F_34 ( struct V_3 * V_4 )
{
if ( ! F_30 ( V_4 -> V_14 ) )
return - V_52 ;
return 0 ;
}
void F_35 ( struct V_3 * V_4 )
{
V_4 -> V_58 = & V_59 ;
V_4 -> type = V_60 ;
V_4 -> V_61 = V_10 ;
V_4 -> V_57 = V_55 ;
V_4 -> V_62 = V_16 ;
V_4 -> V_63 = 1000 ;
V_4 -> V_18 = V_64 | V_65 ;
V_4 -> V_48 |= V_66 ;
memset ( V_4 -> V_29 , 0xFF , V_16 ) ;
}
struct V_3 * F_36 ( int V_67 , unsigned int V_68 ,
unsigned int V_69 )
{
return F_37 ( V_67 , L_2 , V_70 ,
F_35 , V_68 , V_69 ) ;
}
T_3 F_38 ( char * V_71 , const unsigned char * V_47 , int V_7 )
{
return F_39 ( V_71 , V_72 , L_3 , V_7 , V_47 ) ;
}
struct V_1 * * F_40 ( struct V_1 * * V_73 ,
struct V_1 * V_2 )
{
struct V_1 * V_45 , * * V_74 = NULL ;
struct V_8 * V_75 , * V_76 ;
unsigned int V_77 , V_78 ;
const struct V_79 * V_80 ;
T_2 type ;
int V_81 = 1 ;
V_78 = F_41 ( V_2 ) ;
V_77 = V_78 + sizeof( * V_75 ) ;
V_75 = F_42 ( V_2 , V_78 ) ;
if ( F_43 ( V_2 , V_77 ) ) {
V_75 = F_44 ( V_2 , V_77 , V_78 ) ;
if ( F_18 ( ! V_75 ) )
goto V_82;
}
V_81 = 0 ;
for ( V_45 = * V_73 ; V_45 ; V_45 = V_45 -> V_83 ) {
if ( ! F_45 ( V_45 ) -> V_84 )
continue;
V_76 = (struct V_8 * ) ( V_45 -> V_21 + V_78 ) ;
if ( F_46 ( V_75 , V_76 ) ) {
F_45 ( V_45 ) -> V_84 = 0 ;
continue;
}
}
type = V_75 -> V_13 ;
F_47 () ;
V_80 = F_48 ( type ) ;
if ( V_80 == NULL ) {
V_81 = 1 ;
goto V_85;
}
F_49 ( V_2 , sizeof( * V_75 ) ) ;
F_50 ( V_2 , V_75 , sizeof( * V_75 ) ) ;
V_74 = V_80 -> V_86 . V_87 ( V_73 , V_2 ) ;
V_85:
F_51 () ;
V_82:
F_45 ( V_2 ) -> V_81 |= V_81 ;
return V_74 ;
}
int F_52 ( struct V_1 * V_2 , int V_88 )
{
struct V_8 * V_75 = (struct V_8 * ) ( V_2 -> V_21 + V_88 ) ;
T_2 type = V_75 -> V_13 ;
struct V_79 * V_80 ;
int V_89 = - V_90 ;
if ( V_2 -> V_91 )
F_53 ( V_2 , V_88 ) ;
F_47 () ;
V_80 = F_54 ( type ) ;
if ( V_80 != NULL )
V_89 = V_80 -> V_86 . V_92 ( V_2 , V_88 +
sizeof( struct V_8 ) ) ;
F_51 () ;
return V_89 ;
}
static int T_4 F_55 ( void )
{
F_56 ( & V_93 ) ;
return 0 ;
}
