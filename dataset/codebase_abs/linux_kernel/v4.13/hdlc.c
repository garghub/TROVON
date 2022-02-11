static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , struct V_3 * V_7 )
{
struct V_8 * V_9 = F_2 ( V_4 ) ;
if ( ! F_3 ( F_4 ( V_4 ) , & V_10 ) ) {
F_5 ( V_2 ) ;
return 0 ;
}
F_6 ( ! V_9 -> V_11 -> V_12 ) ;
return V_9 -> V_11 -> V_12 ( V_2 ) ;
}
T_1 F_7 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
V_8 * V_9 = F_2 ( V_4 ) ;
if ( V_9 -> V_11 -> V_13 )
return V_9 -> V_11 -> V_13 ( V_2 , V_4 ) ;
return V_9 -> V_13 ( V_2 , V_4 ) ;
}
static inline void F_8 ( struct V_3 * V_4 )
{
V_8 * V_9 = F_2 ( V_4 ) ;
if ( V_9 -> V_11 -> V_14 )
V_9 -> V_11 -> V_14 ( V_4 ) ;
}
static inline void F_9 ( struct V_3 * V_4 )
{
V_8 * V_9 = F_2 ( V_4 ) ;
if ( V_9 -> V_11 -> V_15 )
V_9 -> V_11 -> V_15 ( V_4 ) ;
}
static int F_10 ( struct V_16 * V_17 , unsigned long V_18 ,
void * V_19 )
{
struct V_3 * V_4 = F_11 ( V_19 ) ;
V_8 * V_9 ;
unsigned long V_20 ;
int V_21 ;
if ( ! F_3 ( F_4 ( V_4 ) , & V_10 ) )
return V_22 ;
if ( ! ( V_4 -> V_23 & V_24 ) )
return V_22 ;
if ( V_18 != V_25 )
return V_22 ;
V_21 = F_12 ( V_4 ) ;
#ifdef F_13
F_14 ( V_26 L_1 ,
V_4 -> V_27 , V_21 ) ;
#endif
V_9 = F_2 ( V_4 ) ;
F_15 ( & V_9 -> V_28 , V_20 ) ;
if ( V_9 -> V_29 == V_21 )
goto V_30;
V_9 -> V_29 = V_21 ;
if ( ! V_9 -> V_31 )
goto V_30;
if ( V_9 -> V_29 ) {
F_16 ( V_4 , L_2 ) ;
F_8 ( V_4 ) ;
} else {
F_16 ( V_4 , L_3 ) ;
F_9 ( V_4 ) ;
}
V_30:
F_17 ( & V_9 -> V_28 , V_20 ) ;
return V_22 ;
}
int F_18 ( struct V_3 * V_4 )
{
V_8 * V_9 = F_2 ( V_4 ) ;
#ifdef F_13
F_14 ( V_26 L_4 , V_4 -> V_27 ,
V_9 -> V_29 , V_9 -> V_31 ) ;
#endif
if ( V_9 -> V_11 == NULL )
return - V_32 ;
if ( V_9 -> V_11 -> V_31 ) {
int V_33 = V_9 -> V_11 -> V_31 ( V_4 ) ;
if ( V_33 )
return V_33 ;
}
F_19 ( & V_9 -> V_28 ) ;
if ( V_9 -> V_29 ) {
F_16 ( V_4 , L_2 ) ;
F_8 ( V_4 ) ;
} else
F_16 ( V_4 , L_5 ) ;
V_9 -> V_31 = 1 ;
F_20 ( & V_9 -> V_28 ) ;
return 0 ;
}
void F_21 ( struct V_3 * V_4 )
{
V_8 * V_9 = F_2 ( V_4 ) ;
#ifdef F_13
F_14 ( V_26 L_6 , V_4 -> V_27 ,
V_9 -> V_29 , V_9 -> V_31 ) ;
#endif
F_19 ( & V_9 -> V_28 ) ;
V_9 -> V_31 = 0 ;
if ( V_9 -> V_29 )
F_9 ( V_4 ) ;
F_20 ( & V_9 -> V_28 ) ;
if ( V_9 -> V_11 -> V_34 )
V_9 -> V_11 -> V_34 ( V_4 ) ;
}
int F_22 ( struct V_3 * V_4 , struct V_35 * V_36 , int V_37 )
{
struct V_38 * V_11 = V_39 ;
int V_33 ;
if ( V_37 != V_40 )
return - V_41 ;
if ( F_2 ( V_4 ) -> V_11 ) {
V_33 = F_2 ( V_4 ) -> V_11 -> V_42 ( V_4 , V_36 ) ;
if ( V_33 != - V_41 )
return V_33 ;
}
while ( V_11 ) {
if ( ( V_33 = V_11 -> V_42 ( V_4 , V_36 ) ) != - V_41 )
return V_33 ;
V_11 = V_11 -> V_43 ;
}
return - V_41 ;
}
static void F_23 ( struct V_3 * V_4 )
{
V_4 -> V_20 = V_44 | V_45 ;
V_4 -> V_23 = V_24 ;
V_4 -> V_46 = V_47 ;
V_4 -> V_48 = 68 ;
V_4 -> V_49 = V_47 ;
V_4 -> type = V_50 ;
V_4 -> V_51 = 16 ;
V_4 -> V_52 = 0 ;
V_4 -> V_53 = & V_54 ;
}
static void F_24 ( struct V_3 * V_4 )
{
V_8 * V_9 = F_2 ( V_4 ) ;
F_23 ( V_4 ) ;
V_9 -> V_29 = 1 ;
V_9 -> V_31 = 0 ;
F_25 ( & V_9 -> V_28 ) ;
}
struct V_3 * F_26 ( void * V_55 )
{
struct V_3 * V_4 ;
V_4 = F_27 ( sizeof( struct V_8 ) , L_7 ,
V_56 , F_24 ) ;
if ( V_4 )
F_2 ( V_4 ) -> V_55 = V_55 ;
return V_4 ;
}
void F_28 ( struct V_3 * V_4 )
{
F_29 () ;
F_30 ( V_4 ) ;
F_31 ( V_4 ) ;
F_32 () ;
}
int F_33 ( struct V_3 * V_4 , struct V_38 * V_11 ,
T_2 V_57 )
{
int V_58 ;
V_58 = F_30 ( V_4 ) ;
if ( V_58 )
return V_58 ;
if ( ! F_34 ( V_11 -> V_59 ) )
return - V_32 ;
if ( V_57 ) {
F_2 ( V_4 ) -> V_60 = F_35 ( V_57 , V_61 ) ;
if ( F_2 ( V_4 ) -> V_60 == NULL ) {
F_36 ( V_11 -> V_59 ) ;
return - V_62 ;
}
}
F_2 ( V_4 ) -> V_11 = V_11 ;
return 0 ;
}
int F_30 ( struct V_3 * V_4 )
{
V_8 * V_9 = F_2 ( V_4 ) ;
int V_58 ;
if ( V_9 -> V_11 ) {
V_58 = F_37 ( V_63 , V_4 ) ;
V_58 = F_38 ( V_58 ) ;
if ( V_58 ) {
F_39 ( V_4 , L_8 ) ;
return V_58 ;
}
if ( V_9 -> V_11 -> V_64 )
V_9 -> V_11 -> V_64 ( V_4 ) ;
F_36 ( V_9 -> V_11 -> V_59 ) ;
V_9 -> V_11 = NULL ;
}
F_40 ( V_9 -> V_60 ) ;
V_9 -> V_60 = NULL ;
F_23 ( V_4 ) ;
return 0 ;
}
void F_41 ( struct V_38 * V_11 )
{
F_29 () ;
V_11 -> V_43 = V_39 ;
V_39 = V_11 ;
F_32 () ;
}
void F_42 ( struct V_38 * V_11 )
{
struct V_38 * * V_6 ;
F_29 () ;
V_6 = & V_39 ;
while ( * V_6 != V_11 ) {
F_6 ( ! * V_6 ) ;
V_6 = & ( ( * V_6 ) -> V_43 ) ;
}
* V_6 = V_11 -> V_43 ;
F_32 () ;
}
static int T_3 F_43 ( void )
{
int V_33 ;
F_44 ( L_9 , V_65 ) ;
if ( ( V_33 = F_45 ( & V_66 ) ) != 0 )
return V_33 ;
F_46 ( & V_67 ) ;
return 0 ;
}
static void T_4 F_47 ( void )
{
F_48 ( & V_67 ) ;
F_49 ( & V_66 ) ;
}
