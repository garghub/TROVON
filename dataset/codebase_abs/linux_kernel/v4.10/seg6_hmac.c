static int F_1 ( struct V_1 * V_2 , const void * V_3 )
{
const struct V_4 * V_5 = V_3 ;
return ( V_5 -> V_6 != * ( V_7 * ) V_2 -> V_8 ) ;
}
static inline void F_2 ( struct V_4 * V_5 )
{
F_3 ( V_5 , V_9 ) ;
}
static void F_4 ( void * V_10 , void * V_2 )
{
struct V_4 * V_5 = (struct V_4 * ) V_10 ;
if ( V_5 )
F_2 ( V_5 ) ;
}
static struct V_11 * F_5 ( struct V_12 * V_13 )
{
struct V_11 * V_14 ;
if ( V_13 -> V_15 < ( V_13 -> V_16 + 1 ) * 2 + 5 )
return NULL ;
if ( ! F_6 ( V_13 ) )
return NULL ;
V_14 = (struct V_11 * )
( ( char * ) V_13 + ( ( V_13 -> V_15 + 1 ) << 3 ) - 40 ) ;
if ( V_14 -> V_17 . type != V_18 || V_14 -> V_17 . V_19 != 38 )
return NULL ;
return V_14 ;
}
static struct V_20 * F_7 ( T_1 V_21 )
{
struct V_20 * V_22 ;
int V_23 , V_24 ;
V_24 = sizeof( V_25 ) / sizeof( struct V_20 ) ;
for ( V_23 = 0 ; V_23 < V_24 ; V_23 ++ ) {
V_22 = & V_25 [ V_23 ] ;
if ( V_22 -> V_21 == V_21 )
return V_22 ;
}
return NULL ;
}
static int F_8 ( struct V_4 * V_5 , const char * V_26 , T_1 V_27 ,
T_1 * V_28 , int V_29 )
{
struct V_20 * V_22 ;
struct V_30 * V_31 ;
struct V_32 * V_33 ;
int V_34 , V_35 ;
V_22 = F_7 ( V_5 -> V_21 ) ;
if ( ! V_22 )
return - V_36 ;
V_31 = * F_9 ( V_22 -> V_37 ) ;
V_35 = F_10 ( V_31 ) ;
if ( V_35 > V_29 ) {
F_11 ( L_1 ,
V_35 , V_29 ) ;
return - V_38 ;
}
V_34 = F_12 ( V_31 , V_5 -> V_39 , V_5 -> V_40 ) ;
if ( V_34 < 0 ) {
F_11 ( L_2 , V_34 ) ;
goto V_41;
}
V_33 = * F_9 ( V_22 -> V_42 ) ;
V_33 -> V_31 = V_31 ;
V_34 = F_13 ( V_33 , V_26 , V_27 , V_28 ) ;
if ( V_34 < 0 ) {
F_11 ( L_3 , V_34 ) ;
goto V_41;
}
return V_35 ;
V_41:
return V_34 ;
}
int F_14 ( struct V_4 * V_5 , struct V_12 * V_43 ,
struct V_44 * V_45 , T_1 * V_28 )
{
T_2 V_6 = F_15 ( V_5 -> V_6 ) ;
T_1 V_46 [ V_47 ] ;
int V_48 , V_23 , V_35 , V_49 ;
char * V_50 , * V_51 ;
V_48 = 16 + 1 + 1 + 4 + ( V_43 -> V_16 + 1 ) * 16 ;
if ( V_48 >= V_52 )
return - V_53 ;
F_16 () ;
V_50 = * F_9 ( V_54 ) ;
V_51 = V_50 ;
memcpy ( V_51 , V_45 , 16 ) ;
V_51 += 16 ;
* V_51 ++ = V_43 -> V_16 ;
* V_51 ++ = V_43 -> V_55 ;
memcpy ( V_51 , & V_6 , 4 ) ;
V_51 += 4 ;
for ( V_23 = 0 ; V_23 < V_43 -> V_16 + 1 ; V_23 ++ ) {
memcpy ( V_51 , V_43 -> V_56 + V_23 , 16 ) ;
V_51 += 16 ;
}
V_35 = F_8 ( V_5 , V_50 , V_48 , V_46 ,
V_47 ) ;
F_17 () ;
if ( V_35 < 0 )
return V_35 ;
V_49 = V_57 ;
if ( V_49 > V_35 )
V_49 = V_35 ;
memset ( V_28 , 0 , V_57 ) ;
memcpy ( V_28 , V_46 , V_49 ) ;
return 0 ;
}
bool F_18 ( struct V_58 * V_59 )
{
T_1 V_60 [ V_57 ] ;
struct V_61 * V_61 = F_19 ( V_59 -> V_62 ) ;
struct V_4 * V_5 ;
struct V_11 * V_14 ;
struct V_12 * V_13 ;
struct V_63 * V_64 ;
V_64 = F_20 ( V_59 -> V_62 ) ;
V_13 = (struct V_12 * ) F_21 ( V_59 ) ;
V_14 = F_5 ( V_13 ) ;
if ( V_64 -> V_65 . V_66 > 0 && ! V_14 )
return false ;
if ( V_64 -> V_65 . V_66 < 0 )
return true ;
if ( V_64 -> V_65 . V_66 == 0 && ! V_14 )
return true ;
V_5 = F_22 ( V_61 , F_23 ( V_14 -> V_6 ) ) ;
if ( ! V_5 )
return false ;
if ( F_14 ( V_5 , V_13 , & F_24 ( V_59 ) -> V_45 , V_60 ) )
return false ;
if ( memcmp ( V_60 , V_14 -> V_67 , V_57 ) != 0 )
return false ;
return true ;
}
struct V_4 * F_22 ( struct V_61 * V_61 , T_3 V_8 )
{
struct V_68 * V_69 = F_25 ( V_61 ) ;
struct V_4 * V_5 ;
V_5 = F_26 ( & V_69 -> V_70 , & V_8 , V_71 ) ;
return V_5 ;
}
int F_27 ( struct V_61 * V_61 , T_3 V_8 , struct V_4 * V_5 )
{
struct V_68 * V_69 = F_25 ( V_61 ) ;
int V_72 ;
V_72 = F_28 ( & V_69 -> V_70 , & V_5 -> V_73 ,
V_71 ) ;
return V_72 ;
}
int F_29 ( struct V_61 * V_61 , T_3 V_8 )
{
struct V_68 * V_69 = F_25 ( V_61 ) ;
struct V_4 * V_5 ;
int V_72 = - V_36 ;
V_5 = F_26 ( & V_69 -> V_70 , & V_8 , V_71 ) ;
if ( ! V_5 )
goto V_74;
V_72 = F_30 ( & V_69 -> V_70 , & V_5 -> V_73 ,
V_71 ) ;
if ( V_72 )
goto V_74;
F_2 ( V_5 ) ;
V_74:
return V_72 ;
}
int F_31 ( struct V_61 * V_61 , struct V_44 * V_45 ,
struct V_12 * V_13 )
{
struct V_4 * V_5 ;
struct V_11 * V_14 ;
int V_72 = - V_36 ;
V_14 = F_5 ( V_13 ) ;
if ( ! V_14 )
return - V_75 ;
F_32 () ;
V_5 = F_22 ( V_61 , F_23 ( V_14 -> V_6 ) ) ;
if ( ! V_5 )
goto V_74;
memset ( V_14 -> V_67 , 0 , V_57 ) ;
V_72 = F_14 ( V_5 , V_13 , V_45 , V_14 -> V_67 ) ;
V_74:
F_33 () ;
return V_72 ;
}
static int F_34 ( void )
{
int V_23 ;
V_54 = F_35 ( char * ) ;
if ( ! V_54 )
return - V_38 ;
F_36 (i) {
char * V_50 = F_37 ( V_52 , V_76 ) ;
if ( ! V_50 )
return - V_38 ;
* F_38 ( V_54 , V_23 ) = V_50 ;
}
return 0 ;
}
static int F_39 ( void )
{
struct V_20 * V_22 ;
struct V_30 * V_31 ;
struct V_32 * V_33 ;
int V_23 , V_24 , V_77 ;
V_24 = sizeof( V_25 ) / sizeof( struct V_20 ) ;
for ( V_23 = 0 ; V_23 < V_24 ; V_23 ++ ) {
struct V_30 * * V_78 ;
int V_79 ;
V_22 = & V_25 [ V_23 ] ;
V_22 -> V_37 = F_35 ( struct V_30 * ) ;
if ( ! V_22 -> V_37 )
return - V_38 ;
F_36 (cpu) {
V_31 = F_40 ( V_22 -> V_80 , 0 , V_76 ) ;
if ( F_41 ( V_31 ) )
return F_42 ( V_31 ) ;
V_78 = F_38 ( V_22 -> V_37 , V_77 ) ;
* V_78 = V_31 ;
}
V_78 = F_43 ( V_22 -> V_37 ) ;
V_31 = * V_78 ;
V_79 = sizeof( * V_33 ) + F_44 ( V_31 ) ;
V_22 -> V_42 = F_35 ( struct V_32 * ) ;
if ( ! V_22 -> V_42 )
return - V_38 ;
F_36 (cpu) {
V_33 = F_37 ( V_79 , V_76 ) ;
if ( ! V_33 )
return - V_38 ;
* F_38 ( V_22 -> V_42 , V_77 ) = V_33 ;
}
}
return 0 ;
}
int T_4 F_45 ( void )
{
int V_34 ;
V_34 = F_34 () ;
if ( V_34 < 0 )
goto V_74;
V_34 = F_39 () ;
V_74:
return V_34 ;
}
int T_5 F_46 ( struct V_61 * V_61 )
{
struct V_68 * V_69 = F_25 ( V_61 ) ;
F_47 ( & V_69 -> V_70 , & V_71 ) ;
return 0 ;
}
void F_48 ( void )
{
struct V_20 * V_22 = NULL ;
int V_23 , V_24 , V_77 ;
F_36 (i) {
char * V_50 = * F_38 ( V_54 , V_23 ) ;
F_49 ( V_50 ) ;
}
F_50 ( V_54 ) ;
V_24 = sizeof( V_25 ) / sizeof( struct V_20 ) ;
for ( V_23 = 0 ; V_23 < V_24 ; V_23 ++ ) {
V_22 = & V_25 [ V_23 ] ;
F_36 (cpu) {
struct V_30 * V_31 ;
struct V_32 * V_33 ;
V_33 = * F_38 ( V_22 -> V_42 , V_77 ) ;
F_49 ( V_33 ) ;
V_31 = * F_38 ( V_22 -> V_37 , V_77 ) ;
F_51 ( V_31 ) ;
}
F_50 ( V_22 -> V_37 ) ;
F_50 ( V_22 -> V_42 ) ;
}
}
void T_6 F_52 ( struct V_61 * V_61 )
{
struct V_68 * V_69 = F_25 ( V_61 ) ;
F_53 ( & V_69 -> V_70 , F_4 , NULL ) ;
}
