static void T_1 F_1 ( void )
{
struct V_1 * V_2 ;
const char * V_3 ;
V_3 = F_2 () ;
V_2 = F_3 ( NULL , NULL , V_3 ) ;
if ( ! V_2 )
return;
V_4 = F_4 ( V_2 , 0 ) ;
F_5 ( V_2 ) ;
}
void T_2 F_6 ( char * V_5 )
{
if ( V_4 ) {
F_7 ( & V_4 -> V_6 , 0x52535445 ) ;
F_7 ( & V_4 -> V_7 , 0x2 ) ;
} else {
F_8 ( L_1 ) ;
}
for (; ; )
;
}
static void F_9 ( unsigned int V_8 )
{
struct V_1 * V_2 ;
struct V_9 * V_10 ;
unsigned long V_11 , V_12 , V_13 ;
unsigned long V_14 , V_15 , V_16 , V_17 ;
V_2 = F_3 ( NULL , NULL , L_2 ) ;
if ( ! V_2 ) {
F_8 ( L_3 ) ;
return;
}
V_10 = F_10 ( V_2 , 0 ) ;
if ( F_11 ( V_10 ) ) {
V_10 = F_12 ( V_2 -> V_18 , L_4 ) ;
}
F_5 ( V_2 ) ;
if ( F_11 ( V_10 ) ) {
F_8 ( L_5 ) ;
return;
}
if ( F_13 ( V_10 ) ) {
F_8 ( L_6 ) ;
return;
}
F_14 ( L_7 , V_8 ) ;
V_8 = ( 1000000000 / V_8 ) * 1000 ;
F_14 ( L_8 , V_8 ) ;
V_11 = V_8 / 20 ;
F_14 ( L_9 , V_11 ) ;
V_12 = V_8 - V_11 ;
V_13 = V_8 + V_11 ;
F_14 ( L_10 , V_12 ) ;
F_14 ( L_11 , V_13 ) ;
for ( V_14 = 0 ; V_14 <= V_11 ; V_14 += V_8 / 64 ) {
V_15 = V_8 - V_14 ;
F_14 ( L_12 , V_15 ) ;
F_15 ( V_10 , V_15 ) ;
V_16 = F_16 ( V_10 ) ;
V_17 = abs ( V_8 - V_16 ) ;
if ( V_17 < V_11 )
break;
if ( ! V_14 )
continue;
V_15 = V_8 + V_14 ;
F_14 ( L_12 , V_15 ) ;
F_15 ( V_10 , V_15 ) ;
V_16 = F_16 ( V_10 ) ;
V_17 = abs ( V_8 - V_16 ) ;
if ( V_17 < V_11 )
break;
}
if ( V_14 <= V_11 ) {
F_14 ( L_13 , V_15 ) ;
F_14 ( L_14 ,
V_8 , V_16 , V_17 , V_11 ) ;
return;
}
F_17 ( L_15 ) ;
F_17 ( L_16 ) ;
F_15 ( V_10 , V_8 ) ;
V_16 = F_16 ( V_10 ) ;
V_17 = abs ( V_8 - V_16 ) ;
F_14 ( L_14 ,
V_8 , V_16 , V_17 , V_11 ) ;
}
static enum V_19
F_18 ( enum V_19 V_20 )
{
return V_21 ;
}
static inline void F_19 ( struct V_22 * V_22 )
{
F_20 ( F_21 ( V_22 ) ) ;
F_20 ( F_22 ( V_22 ) > 1 ) ;
F_23 ( V_22 ) ;
}
static void F_24 ( void )
{
unsigned long V_23 = V_24 . V_25 & V_26 ;
unsigned long V_27 = V_24 . V_28 ;
unsigned long V_29 , V_30 ;
if ( V_24 . V_31 ) {
V_29 = F_25 ( V_23 ) ;
V_30 = F_26 ( V_23 + V_27 ) ;
for (; V_29 < V_30 ; V_29 ++ )
F_19 ( F_27 ( V_29 ) ) ;
V_24 . V_31 = false ;
}
V_32 . V_33 = NULL ;
}
static void T_1 F_28 ( void )
{
struct V_1 * V_2 ;
struct V_34 T_3 * V_35 ;
T_4 V_36 ;
void T_3 * V_37 ;
unsigned long V_38 , V_39 , V_40 , V_41 ;
unsigned long V_42 ;
V_2 = F_3 ( NULL , NULL , L_2 ) ;
if ( ! V_2 ) {
F_8 ( L_17 ) ;
return;
}
V_35 = F_4 ( V_2 , 0 ) ;
F_5 ( V_2 ) ;
if ( ! V_35 ) {
F_8 ( L_18 ) ;
return;
}
V_38 = F_29 ( & V_35 -> V_43 ) ;
if ( V_38 == V_44 ) {
F_30 ( L_19 , V_45 ) ;
goto V_46;
}
V_36 = F_29 ( & V_35 -> V_36 [ 0 ] ) ;
V_37 = F_31 ( V_36 , sizeof( struct V_47 ) ) ;
if ( ! V_37 ) {
F_8 ( L_20 ) ;
goto V_46;
}
memcpy ( & V_24 . V_48 , V_37 , sizeof( struct V_47 ) ) ;
V_42 = ( unsigned long ) & V_24 . V_48 ;
F_32 ( V_42 , V_42 + sizeof( struct V_47 ) - 1 ) ;
V_40 = F_29 ( & V_35 -> V_49 ) ;
V_39 = F_33 ( V_37 ) ;
V_41 = ( ( V_39 >> 16 ) & 0x3 ) + 1 ;
V_24 . V_25 = F_33 ( V_37 + 4 ) ;
V_24 . V_28 = ( ( V_40 & 0xfff0000 ) >> 16 ) * ( V_40 & 0xfff ) * V_41 ;
V_24 . V_31 = true ;
F_34 ( V_37 ) ;
V_36 = F_29 ( & V_35 -> gamma ) ;
V_37 = F_31 ( V_36 , sizeof( V_24 . gamma ) ) ;
if ( ! V_37 ) {
F_8 ( L_20 ) ;
V_24 . V_31 = false ;
goto V_46;
}
memcpy ( & V_24 . gamma , V_37 , sizeof( V_24 . gamma ) ) ;
V_42 = ( unsigned long ) & V_24 . gamma ;
F_32 ( V_42 , V_42 + sizeof( V_24 . gamma ) - 1 ) ;
F_34 ( V_37 ) ;
F_7 ( & V_35 -> gamma , F_35 ( & V_24 . gamma ) ) ;
F_7 ( & V_35 -> V_36 [ 1 ] , 0 ) ;
F_7 ( & V_35 -> V_36 [ 2 ] , 0 ) ;
F_7 ( & V_35 -> V_36 [ 0 ] , F_35 ( & V_24 . V_48 ) ) ;
V_46:
F_34 ( V_35 ) ;
}
static void T_1 F_36 ( void )
{
int V_50 ;
if ( V_24 . V_31 ) {
V_50 = F_37 ( V_24 . V_25 ,
V_24 . V_28 ) ;
if ( V_50 ) {
F_8 ( L_21 , V_45 ) ;
V_24 . V_31 = false ;
}
}
V_32 . V_51 = F_9 ;
V_32 . V_52 = F_18 ;
V_32 . V_33 = F_24 ;
}
void T_1 F_38 ( void )
{
struct V_1 * V_2 ;
V_2 = F_3 ( NULL , NULL , L_22 ) ;
if ( ! V_2 )
return;
F_39 ( V_2 , 0 ) ;
F_5 ( V_2 ) ;
F_40 () ;
}
static void T_1 F_41 ( void )
{
if ( F_42 ( NULL , V_53 , NULL ) )
F_43 (KERN_ERR __FILE__ L_23
L_24 ) ;
}
const char * F_44 ( void )
{
if ( F_45 ( L_25 ) )
return L_26 ;
if ( F_45 ( L_27 ) )
return L_28 ;
return NULL ;
}
const char * F_2 ( void )
{
if ( F_45 ( L_25 ) )
return L_29 ;
if ( F_45 ( L_27 ) )
return L_30 ;
return NULL ;
}
static unsigned int T_1 F_46 ( struct V_1 * V_2 ,
char * V_54 )
{
const unsigned int * V_55 ;
V_55 = F_47 ( V_2 , V_54 , NULL ) ;
if ( V_55 )
return * V_55 ;
F_48 ( L_31 ,
V_54 , V_2 , V_56 ) ;
return V_56 ;
}
static void T_1 F_49 ( void )
{
struct V_1 * V_2 ;
void T_3 * V_57 ;
unsigned int V_58 ;
unsigned int V_59 ;
const char * V_60 ;
int V_61 = 0 ;
V_60 = F_44 () ;
if ( ! V_60 ) {
F_8 ( L_32 , V_45 ) ;
return;
}
F_50 (np, NULL, psc_compat) {
V_58 = F_46 ( V_2 , L_33 ) ;
V_59 = F_46 ( V_2 , L_34 ) ;
V_58 /= 4 ;
V_59 /= 4 ;
if ( ! V_58 )
V_58 = 1 ;
if ( ! V_59 )
V_59 = 1 ;
V_57 = F_4 ( V_2 , 0 ) ;
if ( ! V_57 ) {
F_8 ( L_35 ,
V_45 , V_2 ) ;
continue;
}
if ( ( V_61 + V_58 + V_59 ) > 0x1000 ) {
F_8 ( L_36 ,
V_45 , V_2 ) ;
F_34 ( V_57 ) ;
continue;
}
F_7 ( & F_51 ( V_57 ) -> V_62 , ( V_61 << 16 ) | V_58 ) ;
V_61 += V_58 ;
F_7 ( & F_51 ( V_57 ) -> V_63 , ( V_61 << 16 ) | V_59 ) ;
V_61 += V_59 ;
F_7 ( & F_51 ( V_57 ) -> V_64 , 0x80 ) ;
F_7 ( & F_51 ( V_57 ) -> V_64 , 0x01 ) ;
F_7 ( & F_51 ( V_57 ) -> V_65 , 0x80 ) ;
F_7 ( & F_51 ( V_57 ) -> V_65 , 0x01 ) ;
F_34 ( V_57 ) ;
}
}
void T_1 F_52 ( void )
{
F_1 () ;
if ( F_53 ( V_66 ) )
F_28 () ;
}
void T_1 F_54 ( void )
{
F_55 () ;
F_41 () ;
F_49 () ;
}
void T_1 F_56 ( void )
{
if ( F_53 ( V_66 ) )
F_36 () ;
}
int F_57 ( unsigned int V_67 , T_5 V_68 )
{
static struct V_69 T_3 * V_70 ;
struct V_1 * V_2 ;
if ( V_67 > 7 )
return - V_71 ;
if ( ! V_70 ) {
V_2 = F_3 ( NULL , NULL , L_37 ) ;
V_70 = F_4 ( V_2 , 0 ) ;
F_5 ( V_2 ) ;
if ( ! V_70 )
return - V_72 ;
}
F_7 ( & V_70 -> V_73 [ V_67 ] , V_68 ) ;
return 0 ;
}
