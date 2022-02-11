static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_2 ( V_4 ) ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_4 ( V_4 ) ;
return 0 ;
}
static int F_5 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
int V_9 )
{
struct V_10 * V_11 =
F_6 ( & V_6 -> V_12 [ V_9 ] ) ;
T_1 V_13 = V_11 -> V_13 , V_14 = V_11 -> V_14 ;
F_7 () ;
F_8 ( V_15 , V_13 ) ;
F_8 ( V_16 , V_14 ) ;
if ( F_9 () || F_10 () )
goto V_17;
if ( V_9 == 0 ) {
F_11 ( V_15 , F_3 ) ;
F_11 ( V_16 , F_3 ) ;
}
if ( V_13 == V_18 )
F_12 () ;
F_13 () ;
if ( F_14 ( V_15 ) == V_18 )
F_15 () ;
if ( V_9 == 0 ) {
F_11 ( V_15 , F_1 ) ;
F_11 ( V_16 , F_1 ) ;
}
V_17:
F_16 () ;
return V_9 ;
}
static inline int F_17 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
int V_9 )
{
return F_18 ( V_6 , V_8 , V_9 , F_5 ) ;
}
static int F_19 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
int V_9 )
{
struct V_19 * V_20 = & V_6 -> V_12 [ V_9 ] ;
struct V_21 * V_22 = & V_8 -> V_23 [ V_9 ] ;
struct V_10 * V_11 = F_6 ( V_20 ) ;
T_1 V_24 = V_25 ;
T_1 V_26 = V_25 ;
int V_27 = - 1 ;
if ( V_28 ) {
V_24 = V_18 ;
if ( ! F_20 ( V_29 ) )
V_26 = V_18 ;
}
if ( ( V_11 -> V_30 ) &&
( V_11 -> V_13 >= V_24 ) &&
( V_11 -> V_14 >= V_26 ) ) {
return V_9 ;
} else {
int V_31 = V_32 - 1 ;
for (; V_31 >= 0 ; V_31 -- ) {
if ( & V_8 -> V_23 [ V_31 ] == V_22 ) {
V_27 = V_31 ;
break;
}
}
F_21 ( V_27 == - 1 ) ;
V_31 -- ;
for (; V_31 >= 0 ; V_31 -- ) {
V_11 = F_6 ( & V_6 -> V_12 [ V_31 ] ) ;
if ( ( V_11 -> V_30 ) &&
( V_11 -> V_13 >= V_24 ) &&
( V_11 -> V_14 >= V_26 ) ) {
V_27 = V_31 ;
break;
}
}
}
return V_27 ;
}
static int F_22 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
int V_9 )
{
int V_33 ;
T_1 V_34 , V_35 = 0 , V_36 = 0 , V_37 ;
struct V_10 * V_11 ;
int V_38 ;
V_37 = F_23 ( V_39 ) ;
if ( V_37 == V_40 ) {
V_33 = V_8 -> V_41 ;
goto V_42;
}
V_11 = F_6 ( & V_6 -> V_12 [ V_9 ] ) ;
V_34 = V_11 -> V_14 ;
V_35 = V_36 = F_24 ( V_43 ) ;
if ( ( V_35 == V_18 ) &&
( V_34 > V_25 ) )
V_35 = V_25 ;
if ( V_35 != V_36 )
F_8 ( V_43 , V_35 ) ;
V_33 = F_19 ( V_6 , V_8 , V_9 ) ;
V_42:
V_38 = F_17 ( V_6 , V_8 , V_33 ) ;
if ( V_35 != V_36 )
F_8 ( V_43 , V_36 ) ;
return V_38 ;
}
void F_25 ( struct V_44 * V_45 )
{
int V_46 ;
if ( ! V_45 )
return;
for ( V_46 = 0 ; V_46 < V_32 ; V_46 ++ ) {
V_47 [ V_46 ] . V_30 = V_45 [ V_46 ] . V_30 ;
V_47 [ V_46 ] . V_48 =
V_45 [ V_46 ] . V_48 ;
V_47 [ V_46 ] . V_49 =
V_45 [ V_46 ] . V_49 ;
}
return;
}
static inline void F_26 ( struct V_7 * V_8 ,
int V_31 , const char * V_50 )
{
struct V_21 * V_51 = & V_8 -> V_23 [ V_31 ] ;
V_51 -> V_48 = V_47 [ V_31 ] . V_48 ;
V_51 -> V_49 = V_47 [ V_31 ] . V_49 ;
V_51 -> V_52 = V_53 ;
V_51 -> V_54 = F_22 ;
sprintf ( V_51 -> V_55 , L_1 , V_31 + 1 ) ;
strncpy ( V_51 -> V_56 , V_50 , V_57 ) ;
}
static inline struct V_10 * F_27 (
struct V_5 * V_6 ,
int V_31 )
{
struct V_10 * V_11 = & V_58 [ V_31 ] ;
struct V_19 * V_59 = & V_6 -> V_12 [ V_31 ] ;
V_11 -> V_30 = V_47 [ V_31 ] . V_30 ;
F_28 ( V_59 , V_11 ) ;
return V_11 ;
}
int T_2 F_29 ( void )
{
struct V_5 * V_6 ;
struct V_7 * V_8 = & V_60 ;
struct V_10 * V_11 ;
V_15 = F_30 ( L_2 ) ;
V_16 = F_30 ( L_3 ) ;
V_43 = F_30 ( L_4 ) ;
V_39 = F_30 ( L_5 ) ;
V_8 -> V_41 = - 1 ;
V_6 = & F_31 ( V_61 , F_32 () ) ;
F_26 ( V_8 , 0 , L_6 ) ;
( & V_8 -> V_23 [ 0 ] ) -> V_54 = F_17 ;
V_8 -> V_41 = 0 ;
V_11 = F_27 ( V_6 , 0 ) ;
V_11 -> V_30 = 1 ;
V_11 -> V_13 = V_40 ;
V_11 -> V_14 = V_40 ;
F_26 ( V_8 , 1 , L_6 ) ;
V_11 = F_27 ( V_6 , 1 ) ;
V_11 -> V_13 = V_40 ;
V_11 -> V_14 = V_40 ;
F_26 ( V_8 , 2 , L_7 ) ;
V_11 = F_27 ( V_6 , 2 ) ;
V_11 -> V_13 = V_25 ;
V_11 -> V_14 = V_40 ;
F_26 ( V_8 , 3 , L_8 ) ;
V_11 = F_27 ( V_6 , 3 ) ;
V_11 -> V_13 = V_18 ;
V_11 -> V_14 = V_40 ;
F_26 ( V_8 , 4 , L_9 ) ;
V_11 = F_27 ( V_6 , 4 ) ;
V_11 -> V_13 = V_25 ;
V_11 -> V_14 = V_25 ;
F_26 ( V_8 , 5 , L_10 ) ;
V_11 = F_27 ( V_6 , 5 ) ;
V_11 -> V_13 = V_18 ;
V_11 -> V_14 = V_25 ;
F_26 ( V_8 , 6 , L_11 ) ;
V_11 = F_27 ( V_6 , 6 ) ;
if ( F_20 ( V_29 ) ) {
V_11 -> V_30 = 0 ;
F_33 ( L_12 ,
V_62 ) ;
}
V_11 -> V_13 = V_18 ;
V_11 -> V_14 = V_18 ;
V_8 -> V_63 = V_32 ;
F_34 ( & V_60 ) ;
V_6 -> V_63 = V_32 ;
if ( F_35 ( V_6 ) ) {
F_36 ( V_64 L_13 ,
V_62 ) ;
return - V_65 ;
}
return 0 ;
}
int T_2 F_29 ( void )
{
return 0 ;
}
