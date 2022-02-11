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
struct V_1 * V_2 = V_23 ;
V_12 * V_13 ;
unsigned long V_24 ;
int V_25 ;
if ( ! F_4 ( F_5 ( V_2 ) , & V_14 ) )
return V_26 ;
if ( ! ( V_2 -> V_27 & V_28 ) )
return V_26 ;
if ( V_22 != V_29 )
return V_26 ;
V_25 = F_12 ( V_2 ) ;
#ifdef F_13
F_14 ( V_30 L_1 ,
V_2 -> V_31 , V_25 ) ;
#endif
V_13 = F_3 ( V_2 ) ;
F_15 ( & V_13 -> V_32 , V_24 ) ;
if ( V_13 -> V_33 == V_25 )
goto V_34;
V_13 -> V_33 = V_25 ;
if ( ! V_13 -> V_35 )
goto V_34;
if ( V_13 -> V_33 ) {
F_14 ( V_36 L_2 , V_2 -> V_31 ) ;
F_9 ( V_2 ) ;
} else {
F_14 ( V_36 L_3 , V_2 -> V_31 ) ;
F_10 ( V_2 ) ;
}
V_34:
F_16 ( & V_13 -> V_32 , V_24 ) ;
return V_26 ;
}
int F_17 ( struct V_1 * V_2 )
{
V_12 * V_13 = F_3 ( V_2 ) ;
#ifdef F_13
F_14 ( V_30 L_4 , V_2 -> V_31 ,
V_13 -> V_33 , V_13 -> V_35 ) ;
#endif
if ( V_13 -> V_15 == NULL )
return - V_37 ;
if ( V_13 -> V_15 -> V_35 ) {
int V_38 = V_13 -> V_15 -> V_35 ( V_2 ) ;
if ( V_38 )
return V_38 ;
}
F_18 ( & V_13 -> V_32 ) ;
if ( V_13 -> V_33 ) {
F_14 ( V_36 L_2 , V_2 -> V_31 ) ;
F_9 ( V_2 ) ;
} else
F_14 ( V_36 L_5 , V_2 -> V_31 ) ;
V_13 -> V_35 = 1 ;
F_19 ( & V_13 -> V_32 ) ;
return 0 ;
}
void F_20 ( struct V_1 * V_2 )
{
V_12 * V_13 = F_3 ( V_2 ) ;
#ifdef F_13
F_14 ( V_30 L_6 , V_2 -> V_31 ,
V_13 -> V_33 , V_13 -> V_35 ) ;
#endif
F_18 ( & V_13 -> V_32 ) ;
V_13 -> V_35 = 0 ;
if ( V_13 -> V_33 )
F_10 ( V_2 ) ;
F_19 ( & V_13 -> V_32 ) ;
if ( V_13 -> V_15 -> V_39 )
V_13 -> V_15 -> V_39 ( V_2 ) ;
}
int F_21 ( struct V_1 * V_2 , struct V_40 * V_41 , int V_42 )
{
struct V_43 * V_15 = V_44 ;
int V_38 ;
if ( V_42 != V_45 )
return - V_5 ;
if ( F_3 ( V_2 ) -> V_15 ) {
V_38 = F_3 ( V_2 ) -> V_15 -> V_46 ( V_2 , V_41 ) ;
if ( V_38 != - V_5 )
return V_38 ;
}
while ( V_15 ) {
if ( ( V_38 = V_15 -> V_46 ( V_2 , V_41 ) ) != - V_5 )
return V_38 ;
V_15 = V_15 -> V_47 ;
}
return - V_5 ;
}
static void F_22 ( struct V_1 * V_2 )
{
V_2 -> V_24 = V_48 | V_49 ;
V_2 -> V_27 = V_28 ;
V_2 -> V_6 = V_4 ;
V_2 -> type = V_50 ;
V_2 -> V_51 = 16 ;
V_2 -> V_52 = 0 ;
V_2 -> V_53 = & V_54 ;
}
static void F_23 ( struct V_1 * V_2 )
{
V_12 * V_13 = F_3 ( V_2 ) ;
F_22 ( V_2 ) ;
V_13 -> V_33 = 1 ;
V_13 -> V_35 = 0 ;
F_24 ( & V_13 -> V_32 ) ;
}
struct V_1 * F_25 ( void * V_55 )
{
struct V_1 * V_2 ;
V_2 = F_26 ( sizeof( struct V_12 ) , L_7 , F_23 ) ;
if ( V_2 )
F_3 ( V_2 ) -> V_55 = V_55 ;
return V_2 ;
}
void F_27 ( struct V_1 * V_2 )
{
F_28 () ;
F_29 ( V_2 ) ;
F_30 ( V_2 ) ;
F_31 () ;
}
int F_32 ( struct V_1 * V_2 , struct V_43 * V_15 ,
T_2 V_56 )
{
F_30 ( V_2 ) ;
if ( ! F_33 ( V_15 -> V_57 ) )
return - V_37 ;
if ( V_56 )
if ( ( F_3 ( V_2 ) -> V_58 = F_34 ( V_56 ,
V_59 ) ) == NULL ) {
F_14 ( V_60 L_8
L_9 ) ;
F_35 ( V_15 -> V_57 ) ;
return - V_61 ;
}
F_3 ( V_2 ) -> V_15 = V_15 ;
return 0 ;
}
void F_30 ( struct V_1 * V_2 )
{
V_12 * V_13 = F_3 ( V_2 ) ;
if ( V_13 -> V_15 ) {
if ( V_13 -> V_15 -> V_62 )
V_13 -> V_15 -> V_62 ( V_2 ) ;
F_35 ( V_13 -> V_15 -> V_57 ) ;
V_13 -> V_15 = NULL ;
}
F_36 ( V_13 -> V_58 ) ;
V_13 -> V_58 = NULL ;
F_22 ( V_2 ) ;
}
void F_37 ( struct V_43 * V_15 )
{
F_28 () ;
V_15 -> V_47 = V_44 ;
V_44 = V_15 ;
F_31 () ;
}
void F_38 ( struct V_43 * V_15 )
{
struct V_43 * * V_10 ;
F_28 () ;
V_10 = & V_44 ;
while ( * V_10 != V_15 ) {
F_7 ( ! * V_10 ) ;
V_10 = & ( ( * V_10 ) -> V_47 ) ;
}
* V_10 = V_15 -> V_47 ;
F_31 () ;
}
static int T_3 F_39 ( void )
{
int V_38 ;
F_14 ( V_36 L_10 , V_63 ) ;
if ( ( V_38 = F_40 ( & V_64 ) ) != 0 )
return V_38 ;
F_41 ( & V_65 ) ;
return 0 ;
}
static void T_4 F_42 ( void )
{
F_43 ( & V_65 ) ;
F_44 ( & V_64 ) ;
}
