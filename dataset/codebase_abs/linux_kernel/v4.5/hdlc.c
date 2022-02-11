int F_1 ( struct V_1 * V_2 , int V_3 )
{
if ( ( V_3 < 68 ) || ( V_3 > V_4 ) )
return - V_5 ;
V_2 -> V_6 = V_3 ;
return 0 ;
}
static int F_2 ( struct V_7 * V_8 , struct V_1 * V_2 ,
struct V_9 * V_10 , struct V_1 * V_11 )
{
struct V_12 * V_13 = F_3 ( V_2 ) ;
if ( ! F_4 ( F_5 ( V_2 ) , & V_14 ) ) {
F_6 ( V_8 ) ;
return 0 ;
}
F_7 ( ! V_13 -> V_15 -> V_16 ) ;
return V_13 -> V_15 -> V_16 ( V_8 ) ;
}
T_1 F_8 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
V_12 * V_13 = F_3 ( V_2 ) ;
if ( V_13 -> V_15 -> V_17 )
return V_13 -> V_15 -> V_17 ( V_8 , V_2 ) ;
return V_13 -> V_17 ( V_8 , V_2 ) ;
}
static inline void F_9 ( struct V_1 * V_2 )
{
V_12 * V_13 = F_3 ( V_2 ) ;
if ( V_13 -> V_15 -> V_18 )
V_13 -> V_15 -> V_18 ( V_2 ) ;
}
static inline void F_10 ( struct V_1 * V_2 )
{
V_12 * V_13 = F_3 ( V_2 ) ;
if ( V_13 -> V_15 -> V_19 )
V_13 -> V_15 -> V_19 ( V_2 ) ;
}
static int F_11 ( struct V_20 * V_21 , unsigned long V_22 ,
void * V_23 )
{
struct V_1 * V_2 = F_12 ( V_23 ) ;
V_12 * V_13 ;
unsigned long V_24 ;
int V_25 ;
if ( ! F_4 ( F_5 ( V_2 ) , & V_14 ) )
return V_26 ;
if ( ! ( V_2 -> V_27 & V_28 ) )
return V_26 ;
if ( V_22 != V_29 )
return V_26 ;
V_25 = F_13 ( V_2 ) ;
#ifdef F_14
F_15 ( V_30 L_1 ,
V_2 -> V_31 , V_25 ) ;
#endif
V_13 = F_3 ( V_2 ) ;
F_16 ( & V_13 -> V_32 , V_24 ) ;
if ( V_13 -> V_33 == V_25 )
goto V_34;
V_13 -> V_33 = V_25 ;
if ( ! V_13 -> V_35 )
goto V_34;
if ( V_13 -> V_33 ) {
F_17 ( V_2 , L_2 ) ;
F_9 ( V_2 ) ;
} else {
F_17 ( V_2 , L_3 ) ;
F_10 ( V_2 ) ;
}
V_34:
F_18 ( & V_13 -> V_32 , V_24 ) ;
return V_26 ;
}
int F_19 ( struct V_1 * V_2 )
{
V_12 * V_13 = F_3 ( V_2 ) ;
#ifdef F_14
F_15 ( V_30 L_4 , V_2 -> V_31 ,
V_13 -> V_33 , V_13 -> V_35 ) ;
#endif
if ( V_13 -> V_15 == NULL )
return - V_36 ;
if ( V_13 -> V_15 -> V_35 ) {
int V_37 = V_13 -> V_15 -> V_35 ( V_2 ) ;
if ( V_37 )
return V_37 ;
}
F_20 ( & V_13 -> V_32 ) ;
if ( V_13 -> V_33 ) {
F_17 ( V_2 , L_2 ) ;
F_9 ( V_2 ) ;
} else
F_17 ( V_2 , L_5 ) ;
V_13 -> V_35 = 1 ;
F_21 ( & V_13 -> V_32 ) ;
return 0 ;
}
void F_22 ( struct V_1 * V_2 )
{
V_12 * V_13 = F_3 ( V_2 ) ;
#ifdef F_14
F_15 ( V_30 L_6 , V_2 -> V_31 ,
V_13 -> V_33 , V_13 -> V_35 ) ;
#endif
F_20 ( & V_13 -> V_32 ) ;
V_13 -> V_35 = 0 ;
if ( V_13 -> V_33 )
F_10 ( V_2 ) ;
F_21 ( & V_13 -> V_32 ) ;
if ( V_13 -> V_15 -> V_38 )
V_13 -> V_15 -> V_38 ( V_2 ) ;
}
int F_23 ( struct V_1 * V_2 , struct V_39 * V_40 , int V_41 )
{
struct V_42 * V_15 = V_43 ;
int V_37 ;
if ( V_41 != V_44 )
return - V_5 ;
if ( F_3 ( V_2 ) -> V_15 ) {
V_37 = F_3 ( V_2 ) -> V_15 -> V_45 ( V_2 , V_40 ) ;
if ( V_37 != - V_5 )
return V_37 ;
}
while ( V_15 ) {
if ( ( V_37 = V_15 -> V_45 ( V_2 , V_40 ) ) != - V_5 )
return V_37 ;
V_15 = V_15 -> V_46 ;
}
return - V_5 ;
}
static void F_24 ( struct V_1 * V_2 )
{
V_2 -> V_24 = V_47 | V_48 ;
V_2 -> V_27 = V_28 ;
V_2 -> V_6 = V_4 ;
V_2 -> type = V_49 ;
V_2 -> V_50 = 16 ;
V_2 -> V_51 = 0 ;
V_2 -> V_52 = & V_53 ;
}
static void F_25 ( struct V_1 * V_2 )
{
V_12 * V_13 = F_3 ( V_2 ) ;
F_24 ( V_2 ) ;
V_13 -> V_33 = 1 ;
V_13 -> V_35 = 0 ;
F_26 ( & V_13 -> V_32 ) ;
}
struct V_1 * F_27 ( void * V_54 )
{
struct V_1 * V_2 ;
V_2 = F_28 ( sizeof( struct V_12 ) , L_7 ,
V_55 , F_25 ) ;
if ( V_2 )
F_3 ( V_2 ) -> V_54 = V_54 ;
return V_2 ;
}
void F_29 ( struct V_1 * V_2 )
{
F_30 () ;
F_31 ( V_2 ) ;
F_32 ( V_2 ) ;
F_33 () ;
}
int F_34 ( struct V_1 * V_2 , struct V_42 * V_15 ,
T_2 V_56 )
{
int V_57 ;
V_57 = F_31 ( V_2 ) ;
if ( V_57 )
return V_57 ;
if ( ! F_35 ( V_15 -> V_58 ) )
return - V_36 ;
if ( V_56 ) {
F_3 ( V_2 ) -> V_59 = F_36 ( V_56 , V_60 ) ;
if ( F_3 ( V_2 ) -> V_59 == NULL ) {
F_37 ( V_15 -> V_58 ) ;
return - V_61 ;
}
}
F_3 ( V_2 ) -> V_15 = V_15 ;
return 0 ;
}
int F_31 ( struct V_1 * V_2 )
{
V_12 * V_13 = F_3 ( V_2 ) ;
int V_57 ;
if ( V_13 -> V_15 ) {
V_57 = F_38 ( V_62 , V_2 ) ;
V_57 = F_39 ( V_57 ) ;
if ( V_57 ) {
F_40 ( V_2 , L_8 ) ;
return V_57 ;
}
if ( V_13 -> V_15 -> V_63 )
V_13 -> V_15 -> V_63 ( V_2 ) ;
F_37 ( V_13 -> V_15 -> V_58 ) ;
V_13 -> V_15 = NULL ;
}
F_41 ( V_13 -> V_59 ) ;
V_13 -> V_59 = NULL ;
F_24 ( V_2 ) ;
return 0 ;
}
void F_42 ( struct V_42 * V_15 )
{
F_30 () ;
V_15 -> V_46 = V_43 ;
V_43 = V_15 ;
F_33 () ;
}
void F_43 ( struct V_42 * V_15 )
{
struct V_42 * * V_10 ;
F_30 () ;
V_10 = & V_43 ;
while ( * V_10 != V_15 ) {
F_7 ( ! * V_10 ) ;
V_10 = & ( ( * V_10 ) -> V_46 ) ;
}
* V_10 = V_15 -> V_46 ;
F_33 () ;
}
static int T_3 F_44 ( void )
{
int V_37 ;
F_45 ( L_9 , V_64 ) ;
if ( ( V_37 = F_46 ( & V_65 ) ) != 0 )
return V_37 ;
F_47 ( & V_66 ) ;
return 0 ;
}
static void T_4 F_48 ( void )
{
F_49 ( & V_66 ) ;
F_50 ( & V_65 ) ;
}
