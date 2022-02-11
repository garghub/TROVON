static inline bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
return V_2 -> V_4 && ( V_2 -> V_4 -> V_5 & V_3 ) ;
}
static int F_2 ( struct V_6 * V_7 )
{
return 0 ;
}
static const struct V_8 * F_3 ( const char * V_9 )
{
const struct V_10 * V_11 ;
for ( V_11 = V_12 ; V_11 -> V_11 [ 0 ] ; V_11 ++ )
if ( ! strcmp ( V_11 -> V_11 , V_9 ) )
return ( const struct V_8 * ) V_11 -> V_13 ;
return NULL ;
}
static int F_4 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = & V_15 -> V_17 ;
T_1 V_18 = F_5 ( V_17 ) ;
struct V_19 * V_16 ;
struct V_1 * V_2 ;
struct V_6 * V_7 ;
struct V_20 * V_21 ;
T_2 V_22 ;
const char * V_9 ;
int V_23 ;
if ( F_6 ( V_18 , & V_16 ) )
return - V_24 ;
if ( F_7 ( V_16 ) || ! V_16 -> V_25 . V_26 )
return - V_24 ;
V_9 = F_8 ( V_16 ) ;
V_21 = F_9 ( V_15 , V_27 , 0 ) ;
if ( ! V_21 )
return - V_28 ;
V_22 = F_10 ( V_21 ) ;
if ( V_22 < 0x100 )
F_11 ( V_17 , L_1 ) ;
if ( ! F_12 ( V_17 , V_21 -> V_29 , V_22 , F_13 ( V_17 ) ) )
return - V_28 ;
V_7 = F_14 ( V_17 , sizeof( struct V_1 ) ) ;
if ( F_15 ( V_7 ) )
return F_16 ( V_7 ) ;
V_2 = F_17 ( V_7 ) ;
V_2 -> V_7 = V_7 ;
V_2 -> V_4 = F_3 ( V_9 ) ;
V_2 -> V_15 = V_15 ;
V_2 -> V_30 = F_1 ( V_2 , V_31 ) ;
F_18 ( V_15 , V_2 ) ;
V_7 -> V_32 = L_2 ;
V_7 -> V_33 = & V_34 ;
V_7 -> V_35 = F_19 ( V_15 , 0 ) ;
V_7 -> V_36 = F_20 ( V_17 , V_21 -> V_29 ,
F_10 ( V_21 ) ) ;
if ( V_7 -> V_36 == NULL ) {
V_23 = - V_28 ;
goto V_37;
}
if ( ! V_17 -> V_38 ) {
T_3 V_38 ;
if ( F_21 ( V_7 , V_39 ) & V_40 ) {
V_38 = F_22 ( 32 ) ;
} else {
V_38 = F_22 ( 32 ) ;
}
V_17 -> V_38 = & V_17 -> V_41 ;
V_17 -> V_41 = V_38 ;
}
if ( V_2 -> V_4 ) {
if ( V_2 -> V_4 -> V_42 ) {
V_7 -> V_33 = V_2 -> V_4 -> V_42 -> V_33 ;
V_7 -> V_43 |= V_2 -> V_4 -> V_42 -> V_43 ;
V_7 -> V_44 |= V_2 -> V_4 -> V_42 -> V_44 ;
V_7 -> V_45 -> V_46 |= V_2 -> V_4 -> V_42 -> V_46 ;
V_7 -> V_45 -> V_47 |= V_2 -> V_4 -> V_42 -> V_47 ;
V_7 -> V_45 -> V_48 |= V_2 -> V_4 -> V_42 -> V_48 ;
}
V_7 -> V_43 |= V_2 -> V_4 -> V_43 ;
V_7 -> V_44 |= V_2 -> V_4 -> V_44 ;
V_7 -> V_45 -> V_46 |= V_2 -> V_4 -> V_46 ;
V_7 -> V_45 -> V_47 |= V_2 -> V_4 -> V_47 ;
V_7 -> V_45 -> V_48 |= V_2 -> V_4 -> V_48 ;
}
V_23 = F_23 ( V_7 ) ;
if ( V_23 )
goto V_37;
if ( V_2 -> V_30 ) {
F_24 ( V_17 , 1 ) ;
F_25 ( V_17 , 50 ) ;
F_26 ( V_17 ) ;
F_27 ( V_17 ) ;
}
return 0 ;
V_37:
F_18 ( V_15 , NULL ) ;
F_28 ( V_2 -> V_7 ) ;
return V_23 ;
}
static int F_29 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_30 ( V_15 ) ;
struct V_16 * V_17 = & V_15 -> V_17 ;
int V_49 ;
if ( V_2 -> V_30 ) {
F_31 ( V_17 ) ;
F_32 ( V_17 ) ;
F_33 ( V_17 ) ;
}
V_49 = ( F_21 ( V_2 -> V_7 , V_50 ) == ~ 0 ) ;
F_34 ( V_2 -> V_7 , V_49 ) ;
F_18 ( V_15 , NULL ) ;
F_28 ( V_2 -> V_7 ) ;
return 0 ;
}
static int F_35 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = F_36 ( V_17 ) ;
return F_37 ( V_2 -> V_7 ) ;
}
static int F_38 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = F_36 ( V_17 ) ;
return F_39 ( V_2 -> V_7 ) ;
}
static int F_40 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = F_36 ( V_17 ) ;
return F_41 ( V_2 -> V_7 ) ;
}
static int F_42 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = F_36 ( V_17 ) ;
return F_43 ( V_2 -> V_7 ) ;
}
static int F_44 ( struct V_16 * V_17 )
{
return 0 ;
}
