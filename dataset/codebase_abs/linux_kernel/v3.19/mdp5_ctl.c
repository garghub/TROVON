static inline
struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 -> V_7 ;
return F_2 ( F_3 ( V_5 -> V_8 ) ) ;
}
static inline
void F_4 ( struct V_9 * V_10 , T_1 V_11 , T_1 V_12 )
{
struct V_1 * V_1 = F_1 ( V_10 -> V_13 ) ;
( void ) V_10 -> V_14 ;
F_5 ( V_1 , V_11 , V_12 ) ;
}
static inline
T_1 F_6 ( struct V_9 * V_10 , T_1 V_11 )
{
struct V_1 * V_1 = F_1 ( V_10 -> V_13 ) ;
( void ) V_10 -> V_14 ;
return F_7 ( V_1 , V_11 ) ;
}
int F_8 ( struct V_9 * V_10 , enum V_15 V_16 )
{
unsigned long V_17 ;
static const enum V_18 V_19 [] = {
V_20 , V_21 , V_22 , V_23 ,
} ;
F_9 ( & V_10 -> V_24 , V_17 ) ;
F_4 ( V_10 , F_10 ( V_10 -> V_25 ) ,
F_11 ( V_10 -> V_26 ) |
F_12 ( V_19 [ V_16 ] ) ) ;
F_13 ( & V_10 -> V_24 , V_17 ) ;
return 0 ;
}
int F_14 ( struct V_9 * V_10 , bool V_27 )
{
struct V_2 * V_3 = V_10 -> V_13 ;
unsigned long V_17 ;
T_1 V_28 ;
int V_29 ;
V_29 = F_15 ( V_10 -> V_30 ) ;
if ( F_16 ( F_17 ( V_29 < 0 ) ) ) {
F_18 ( V_3 -> V_6 -> V_6 , L_1 ,
V_10 -> V_25 , V_29 ) ;
return - V_31 ;
}
F_9 ( & V_10 -> V_24 , V_17 ) ;
V_28 = F_6 ( V_10 , F_19 ( V_10 -> V_25 , V_29 ) ) ;
if ( V_27 )
V_28 |= V_32 ;
else
V_28 &= ~ V_32 ;
F_4 ( V_10 , F_19 ( V_10 -> V_25 , V_29 ) , V_28 ) ;
F_13 ( & V_10 -> V_24 , V_17 ) ;
V_10 -> V_33 = V_27 ;
return 0 ;
}
int F_20 ( struct V_9 * V_10 , T_1 V_29 , T_1 V_28 )
{
unsigned long V_17 ;
if ( V_10 -> V_33 )
V_28 |= V_32 ;
else
V_28 &= ~ V_32 ;
F_9 ( & V_10 -> V_24 , V_17 ) ;
F_4 ( V_10 , F_19 ( V_10 -> V_25 , V_29 ) , V_28 ) ;
F_13 ( & V_10 -> V_24 , V_17 ) ;
return 0 ;
}
int F_21 ( struct V_9 * V_10 , T_1 V_34 )
{
struct V_2 * V_3 = V_10 -> V_13 ;
unsigned long V_17 ;
if ( V_34 & V_35 ) {
int V_29 = F_15 ( V_10 -> V_30 ) ;
if ( F_16 ( F_17 ( V_29 < 0 ) ) ) {
F_18 ( V_3 -> V_6 -> V_6 , L_1 ,
V_10 -> V_25 , V_29 ) ;
return - V_31 ;
}
V_34 |= F_22 ( V_29 ) ;
}
F_9 ( & V_10 -> V_24 , V_17 ) ;
F_4 ( V_10 , F_23 ( V_10 -> V_25 ) , V_34 ) ;
F_13 ( & V_10 -> V_24 , V_17 ) ;
return 0 ;
}
T_1 F_24 ( struct V_9 * V_10 )
{
return V_10 -> V_34 ;
}
void F_25 ( struct V_9 * V_10 )
{
struct V_2 * V_3 = V_10 -> V_13 ;
unsigned long V_17 ;
if ( F_16 ( F_17 ( V_10 -> V_25 >= V_36 ) || ! V_10 -> V_37 ) ) {
F_18 ( V_3 -> V_6 -> V_6 , L_2 ,
V_10 -> V_25 , V_10 -> V_37 ) ;
return;
}
F_9 ( & V_3 -> V_38 , V_17 ) ;
V_10 -> V_37 = false ;
F_13 ( & V_3 -> V_38 , V_17 ) ;
F_26 ( L_3 , V_10 -> V_25 ) ;
}
struct V_9 * F_27 ( struct V_2 * V_3 ,
struct V_39 * V_30 )
{
struct V_9 * V_10 = NULL ;
unsigned long V_17 ;
int V_40 ;
F_9 ( & V_3 -> V_38 , V_17 ) ;
for ( V_40 = 0 ; V_40 < V_3 -> V_41 ; V_40 ++ )
if ( ! V_3 -> V_42 [ V_40 ] . V_37 )
break;
if ( F_16 ( V_40 >= V_3 -> V_41 ) ) {
F_18 ( V_3 -> V_6 -> V_6 , L_4 ) ;
goto V_43;
}
V_10 = & V_3 -> V_42 [ V_40 ] ;
V_10 -> V_30 = V_30 ;
V_10 -> V_37 = true ;
F_26 ( L_5 , V_10 -> V_25 ) ;
V_43:
F_13 ( & V_3 -> V_38 , V_17 ) ;
return V_10 ;
}
void F_28 ( struct V_2 * V_3 )
{
unsigned long V_17 ;
int V_40 ;
for ( V_40 = 0 ; V_40 < V_3 -> V_41 ; V_40 ++ ) {
struct V_9 * V_10 = & V_3 -> V_42 [ V_40 ] ;
F_9 ( & V_10 -> V_24 , V_17 ) ;
F_4 ( V_10 , F_10 ( V_10 -> V_25 ) , 0 ) ;
F_13 ( & V_10 -> V_24 , V_17 ) ;
}
}
void F_29 ( struct V_2 * V_3 )
{
F_30 ( V_3 ) ;
}
struct V_2 * F_31 ( struct V_44 * V_6 ,
void T_2 * V_45 , const struct V_46 * V_47 )
{
struct V_2 * V_3 ;
const struct V_48 * V_49 = & V_47 -> V_10 ;
unsigned long V_17 ;
int V_40 , V_50 ;
V_3 = F_32 ( sizeof( * V_3 ) , V_51 ) ;
if ( ! V_3 ) {
F_18 ( V_6 -> V_6 , L_6 ) ;
V_50 = - V_52 ;
goto V_53;
}
if ( F_16 ( F_17 ( V_49 -> V_54 > V_36 ) ) ) {
F_18 ( V_6 -> V_6 , L_7 ,
V_49 -> V_54 ) ;
V_50 = - V_55 ;
goto V_53;
}
V_3 -> V_6 = V_6 ;
V_3 -> V_56 = V_47 -> V_29 . V_54 ;
V_3 -> V_41 = V_49 -> V_54 ;
F_33 ( & V_3 -> V_38 ) ;
F_9 ( & V_3 -> V_38 , V_17 ) ;
for ( V_40 = 0 ; V_40 < V_3 -> V_41 ; V_40 ++ ) {
struct V_9 * V_10 = & V_3 -> V_42 [ V_40 ] ;
if ( F_17 ( ! V_49 -> V_57 [ V_40 ] ) ) {
F_18 ( V_6 -> V_6 , L_8 , V_40 ) ;
V_50 = - V_31 ;
goto V_53;
}
V_10 -> V_13 = V_3 ;
V_10 -> V_25 = V_40 ;
V_10 -> V_26 = V_58 ;
V_10 -> V_14 = V_49 -> V_57 [ V_40 ] ;
V_10 -> V_34 = V_59 ;
V_10 -> V_37 = false ;
F_33 ( & V_10 -> V_24 ) ;
}
F_13 ( & V_3 -> V_38 , V_17 ) ;
F_26 ( L_9 , V_3 -> V_41 ) ;
return V_3 ;
V_53:
if ( V_3 )
F_29 ( V_3 ) ;
return F_34 ( V_50 ) ;
}
