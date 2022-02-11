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
int F_8 ( struct V_9 * V_10 , int V_15 )
{
unsigned long V_16 ;
static const enum V_17 V_18 [] = {
V_19 , V_20 , V_21 , V_22 ,
} ;
F_9 ( & V_10 -> V_23 , V_16 ) ;
F_4 ( V_10 , F_10 ( V_10 -> V_24 ) ,
F_11 ( V_10 -> V_25 ) |
F_12 ( V_18 [ V_15 ] ) ) ;
F_13 ( & V_10 -> V_23 , V_16 ) ;
return 0 ;
}
int F_14 ( struct V_9 * V_10 , bool V_26 )
{
struct V_2 * V_3 = V_10 -> V_13 ;
unsigned long V_16 ;
T_1 V_27 ;
int V_28 ;
V_28 = F_15 ( V_10 -> V_29 ) ;
if ( F_16 ( F_17 ( V_28 < 0 ) ) ) {
F_18 ( V_3 -> V_6 -> V_6 , L_1 ,
V_10 -> V_24 , V_28 ) ;
return - V_30 ;
}
F_9 ( & V_10 -> V_23 , V_16 ) ;
V_27 = F_6 ( V_10 , F_19 ( V_10 -> V_24 , V_28 ) ) ;
if ( V_26 )
V_27 |= V_31 ;
else
V_27 &= ~ V_31 ;
F_4 ( V_10 , F_19 ( V_10 -> V_24 , V_28 ) , V_27 ) ;
F_13 ( & V_10 -> V_23 , V_16 ) ;
V_10 -> V_32 = V_26 ;
return 0 ;
}
int F_20 ( struct V_9 * V_10 , T_1 V_28 , T_1 V_27 )
{
unsigned long V_16 ;
if ( V_10 -> V_32 )
V_27 |= V_31 ;
else
V_27 &= ~ V_31 ;
F_9 ( & V_10 -> V_23 , V_16 ) ;
F_4 ( V_10 , F_19 ( V_10 -> V_24 , V_28 ) , V_27 ) ;
F_13 ( & V_10 -> V_23 , V_16 ) ;
return 0 ;
}
int F_21 ( struct V_9 * V_10 , T_1 V_33 )
{
struct V_2 * V_3 = V_10 -> V_13 ;
unsigned long V_16 ;
if ( V_33 & V_34 ) {
int V_28 = F_15 ( V_10 -> V_29 ) ;
if ( F_16 ( F_17 ( V_28 < 0 ) ) ) {
F_18 ( V_3 -> V_6 -> V_6 , L_1 ,
V_10 -> V_24 , V_28 ) ;
return - V_30 ;
}
V_33 |= F_22 ( V_28 ) ;
}
F_9 ( & V_10 -> V_23 , V_16 ) ;
F_4 ( V_10 , F_23 ( V_10 -> V_24 ) , V_33 ) ;
F_13 ( & V_10 -> V_23 , V_16 ) ;
return 0 ;
}
T_1 F_24 ( struct V_9 * V_10 )
{
return V_10 -> V_33 ;
}
void F_25 ( struct V_9 * V_10 )
{
struct V_2 * V_3 = V_10 -> V_13 ;
unsigned long V_16 ;
if ( F_16 ( F_17 ( V_10 -> V_24 >= V_35 ) || ! V_10 -> V_36 ) ) {
F_18 ( V_3 -> V_6 -> V_6 , L_2 ,
V_10 -> V_24 , V_10 -> V_36 ) ;
return;
}
F_9 ( & V_3 -> V_37 , V_16 ) ;
V_10 -> V_36 = false ;
F_13 ( & V_3 -> V_37 , V_16 ) ;
F_26 ( L_3 , V_10 -> V_24 ) ;
}
struct V_9 * F_27 ( struct V_2 * V_3 ,
struct V_38 * V_29 )
{
struct V_9 * V_10 = NULL ;
unsigned long V_16 ;
int V_39 ;
F_9 ( & V_3 -> V_37 , V_16 ) ;
for ( V_39 = 0 ; V_39 < V_3 -> V_40 ; V_39 ++ )
if ( ! V_3 -> V_41 [ V_39 ] . V_36 )
break;
if ( F_16 ( V_39 >= V_3 -> V_40 ) ) {
F_18 ( V_3 -> V_6 -> V_6 , L_4 ) ;
goto V_42;
}
V_10 = & V_3 -> V_41 [ V_39 ] ;
V_10 -> V_29 = V_29 ;
V_10 -> V_36 = true ;
F_26 ( L_5 , V_10 -> V_24 ) ;
V_42:
F_13 ( & V_3 -> V_37 , V_16 ) ;
return V_10 ;
}
void F_28 ( struct V_2 * V_3 )
{
unsigned long V_16 ;
int V_39 ;
for ( V_39 = 0 ; V_39 < V_3 -> V_40 ; V_39 ++ ) {
struct V_9 * V_10 = & V_3 -> V_41 [ V_39 ] ;
F_9 ( & V_10 -> V_23 , V_16 ) ;
F_4 ( V_10 , F_10 ( V_10 -> V_24 ) , 0 ) ;
F_13 ( & V_10 -> V_23 , V_16 ) ;
}
}
void F_29 ( struct V_2 * V_3 )
{
F_30 ( V_3 ) ;
}
struct V_2 * F_31 ( struct V_43 * V_6 ,
void T_2 * V_44 , const struct V_45 * V_46 )
{
struct V_2 * V_3 ;
const struct V_47 * V_48 = & V_46 -> V_10 ;
unsigned long V_16 ;
int V_39 , V_49 ;
V_3 = F_32 ( sizeof( * V_3 ) , V_50 ) ;
if ( ! V_3 ) {
F_18 ( V_6 -> V_6 , L_6 ) ;
V_49 = - V_51 ;
goto V_52;
}
if ( F_16 ( F_17 ( V_48 -> V_53 > V_35 ) ) ) {
F_18 ( V_6 -> V_6 , L_7 ,
V_48 -> V_53 ) ;
V_49 = - V_54 ;
goto V_52;
}
V_3 -> V_6 = V_6 ;
V_3 -> V_55 = V_46 -> V_28 . V_53 ;
V_3 -> V_40 = V_48 -> V_53 ;
F_33 ( & V_3 -> V_37 ) ;
F_9 ( & V_3 -> V_37 , V_16 ) ;
for ( V_39 = 0 ; V_39 < V_3 -> V_40 ; V_39 ++ ) {
struct V_9 * V_10 = & V_3 -> V_41 [ V_39 ] ;
if ( F_17 ( ! V_48 -> V_56 [ V_39 ] ) ) {
F_18 ( V_6 -> V_6 , L_8 , V_39 ) ;
V_49 = - V_30 ;
goto V_52;
}
V_10 -> V_13 = V_3 ;
V_10 -> V_24 = V_39 ;
V_10 -> V_25 = V_57 ;
V_10 -> V_14 = V_48 -> V_56 [ V_39 ] ;
V_10 -> V_33 = V_58 ;
V_10 -> V_36 = false ;
F_33 ( & V_10 -> V_23 ) ;
}
F_13 ( & V_3 -> V_37 , V_16 ) ;
F_26 ( L_9 , V_3 -> V_40 ) ;
return V_3 ;
V_52:
if ( V_3 )
F_29 ( V_3 ) ;
return F_34 ( V_49 ) ;
}
