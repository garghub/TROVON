static inline void F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_4 )
{
F_2 ( V_4 , V_2 -> V_5 + V_3 ) ;
}
static inline T_1 F_3 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_4 ( V_2 -> V_5 + V_3 ) ;
}
static inline struct V_1 * F_5 ( struct V_6 * V_7 )
{
return F_6 ( V_7 , struct V_1 , V_7 ) ;
}
static inline T_1 F_7 ( T_1 V_3 )
{
if ( F_8 ( V_3 ) )
return 1 ;
return F_9 ( V_3 ) + F_10 ( V_3 ) ;
}
static inline T_1 F_11 ( unsigned int V_8 , int V_9 )
{
T_1 div = 0 ;
F_12 ( div , ( V_8 % 2 == 0 ) ? V_8 >> 1 : ( V_8 >> 1 ) + 1 ) ;
F_13 ( div , V_8 >> 1 ) ;
F_14 ( div , V_8 % 2 ) ;
F_15 ( div , V_8 == 1 ? 1 : 0 ) ;
F_16 ( div , V_9 == 0 ? 1 : 0 ) ;
return div ;
}
static unsigned long F_17 ( struct V_6 * V_7 ,
unsigned long V_10 )
{
T_2 V_11 ;
T_1 V_12 , V_13 , V_14 ;
struct V_1 * V_2 = F_5 ( V_7 ) ;
V_12 = F_7 ( F_3 ( V_2 , V_15 ) ) ;
V_13 = F_7 ( F_3 ( V_2 , V_16 ) ) ;
V_14 = F_7 ( F_3 ( V_2 , V_17 ) ) ;
V_11 = ( T_2 ) V_10 * V_13 ;
F_18 ( V_11 , V_12 * V_14 ) ;
return V_11 ;
}
static long F_19 ( struct V_6 * V_7 , unsigned long V_11 ,
unsigned long * V_18 )
{
int V_19 ;
long V_20 ;
struct V_1 * V_2 = F_5 ( V_7 ) ;
const struct V_21 * V_22 = V_2 -> V_22 ;
if ( V_22 [ 0 ] . V_11 == 0 )
return - V_23 ;
V_20 = V_22 [ 0 ] . V_11 ;
for ( V_19 = 1 ; V_22 [ V_19 ] . V_11 != 0 ; V_19 ++ ) {
if ( abs ( V_11 - V_22 [ V_19 ] . V_11 ) < abs ( V_11 - V_20 ) )
V_20 = V_22 [ V_19 ] . V_11 ;
}
return V_20 ;
}
static int F_20 ( struct V_6 * V_7 , unsigned long V_11 ,
unsigned long V_10 )
{
int V_19 ;
struct V_1 * V_2 = F_5 ( V_7 ) ;
const struct V_21 * V_22 = V_2 -> V_22 ;
for ( V_19 = 0 ; V_22 [ V_19 ] . V_11 != 0 ; V_19 ++ ) {
if ( V_22 [ V_19 ] . V_11 == V_11 ) {
F_1 ( V_2 , V_15 ,
F_11 ( V_22 [ V_19 ] . V_12 , 0 ) ) ;
F_1 ( V_2 , V_16 ,
F_11 ( V_22 [ V_19 ] . V_13 , 0 ) ) ;
F_1 ( V_2 , V_17 ,
F_11 ( V_22 [ V_19 ] . V_14 , 1 ) ) ;
F_21 ( V_24 ) ;
if ( ! ( F_4 ( V_2 -> V_25 ) & V_26 ) )
return - V_27 ;
if ( F_4 ( V_2 -> V_25 ) & V_28 )
return - V_23 ;
return 0 ;
}
}
F_22 ( V_2 -> V_29 , L_1 , V_11 ,
V_10 ) ;
return - V_23 ;
}
static int F_23 ( struct V_30 * V_31 )
{
struct V_32 * V_29 = & V_31 -> V_29 ;
const char * V_33 ;
struct V_1 * V_34 ;
struct V_35 * V_36 ;
struct V_37 V_38 = { } ;
int V_39 ;
V_34 = F_24 ( V_29 , sizeof( * V_34 ) , V_40 ) ;
if ( ! V_34 )
return - V_41 ;
V_36 = F_25 ( V_31 , V_42 , 0 ) ;
V_34 -> V_5 = F_26 ( V_29 , V_36 ) ;
if ( F_27 ( V_34 -> V_5 ) )
return F_28 ( V_34 -> V_5 ) ;
V_36 = F_25 ( V_31 , V_42 , 1 ) ;
V_34 -> V_25 = F_26 ( V_29 , V_36 ) ;
if ( F_27 ( V_34 -> V_25 ) )
return F_28 ( V_34 -> V_25 ) ;
V_38 . V_43 = V_29 -> V_44 -> V_43 ;
V_38 . V_45 = & V_46 ;
V_33 = F_29 ( V_29 -> V_44 , 0 ) ;
V_38 . V_47 = & V_33 ;
V_38 . V_48 = 1 ;
V_34 -> V_7 . V_38 = & V_38 ;
V_34 -> V_29 = V_29 ;
V_34 -> V_22 = F_30 ( V_29 ) ;
if ( ! V_34 -> V_22 ) {
F_22 ( V_29 , L_2 ) ;
return - V_23 ;
}
V_39 = F_31 ( V_29 , & V_34 -> V_7 ) ;
if ( V_39 ) {
F_22 ( V_29 , L_3 , V_38 . V_43 ) ;
return V_39 ;
}
return F_32 ( V_29 -> V_44 , V_49 ,
& V_34 -> V_7 ) ;
}
static int F_33 ( struct V_30 * V_31 )
{
F_34 ( V_31 -> V_29 . V_44 ) ;
return 0 ;
}
static void T_3 F_35 ( struct V_50 * V_51 )
{
const char * V_33 ;
struct V_1 * V_34 ;
struct V_37 V_38 = { } ;
int V_39 ;
V_34 = F_36 ( sizeof( * V_34 ) , V_40 ) ;
if ( ! V_34 )
return;
V_34 -> V_5 = F_37 ( V_51 , 0 ) ;
if ( ! V_34 -> V_5 ) {
F_38 ( L_4 ) ;
goto V_52;
}
V_34 -> V_25 = F_37 ( V_51 , 1 ) ;
if ( ! V_34 -> V_25 ) {
F_38 ( L_5 ) ;
goto V_53;
}
V_38 . V_43 = V_51 -> V_43 ;
V_38 . V_45 = & V_46 ;
V_33 = F_29 ( V_51 , 0 ) ;
V_38 . V_47 = & V_33 ;
V_38 . V_48 = V_33 ? 1 : 0 ;
V_34 -> V_7 . V_38 = & V_38 ;
V_34 -> V_22 = V_54 ;
V_39 = F_39 ( NULL , & V_34 -> V_7 ) ;
if ( V_39 ) {
F_38 ( L_3 , V_51 -> V_43 ) ;
goto V_55;
}
V_39 = F_32 ( V_51 , V_49 , & V_34 -> V_7 ) ;
if ( V_39 ) {
F_38 ( L_6 , V_51 -> V_43 ) ;
goto V_56;
}
return;
V_56:
F_40 ( & V_34 -> V_7 ) ;
V_55:
F_41 ( V_34 -> V_25 ) ;
V_53:
F_41 ( V_34 -> V_5 ) ;
V_52:
F_42 ( V_34 ) ;
}
