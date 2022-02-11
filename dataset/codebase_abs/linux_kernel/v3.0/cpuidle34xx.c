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
struct V_7 * V_8 )
{
struct V_9 * V_10 = F_6 ( V_8 ) ;
struct V_11 V_12 , V_13 , V_14 ;
T_1 V_15 = V_10 -> V_15 , V_16 = V_10 -> V_16 ;
F_7 ( & V_12 ) ;
F_8 () ;
F_9 () ;
F_10 ( V_17 , V_15 ) ;
F_10 ( V_18 , V_16 ) ;
if ( F_11 () || F_12 () )
goto V_19;
if ( V_8 == & V_6 -> V_20 [ 0 ] ) {
F_13 ( V_17 , F_3 ) ;
F_13 ( V_18 , F_3 ) ;
}
F_14 () ;
if ( V_8 == & V_6 -> V_20 [ 0 ] ) {
F_13 ( V_17 , F_1 ) ;
F_13 ( V_18 , F_1 ) ;
}
V_19:
F_7 ( & V_13 ) ;
V_14 = F_15 ( V_13 , V_12 ) ;
F_16 () ;
F_17 () ;
return V_14 . V_21 / V_22 + V_14 . V_23 * V_24 ;
}
static struct V_7 * F_18 ( struct V_5 * V_6 ,
struct V_7 * V_25 )
{
struct V_7 * V_26 = NULL ;
struct V_9 * V_10 = F_6 ( V_25 ) ;
T_1 V_27 = V_28 ;
T_1 V_29 = V_28 ;
if ( V_30 ) {
V_27 = V_31 ;
if ( ! F_19 ( V_32 ) )
V_29 = V_31 ;
}
if ( ( V_10 -> V_33 ) &&
( V_10 -> V_15 >= V_27 ) &&
( V_10 -> V_16 >= V_29 ) ) {
return V_25 ;
} else {
int V_34 = V_35 - 1 ;
for (; V_34 >= 0 ; V_34 -- ) {
if ( & V_6 -> V_20 [ V_34 ] == V_25 ) {
V_26 = & V_6 -> V_20 [ V_34 ] ;
break;
}
}
F_20 ( V_26 == NULL ) ;
V_34 -- ;
for (; V_34 >= 0 ; V_34 -- ) {
V_10 = F_6 ( & V_6 -> V_20 [ V_34 ] ) ;
if ( ( V_10 -> V_33 ) &&
( V_10 -> V_15 >= V_27 ) &&
( V_10 -> V_16 >= V_29 ) ) {
V_26 = & V_6 -> V_20 [ V_34 ] ;
break;
}
}
}
return V_26 ;
}
static int F_21 ( struct V_5 * V_6 ,
struct V_7 * V_8 )
{
struct V_7 * V_36 ;
T_1 V_37 , V_38 = 0 , V_39 = 0 , V_40 ;
struct V_9 * V_10 ;
int V_41 ;
if ( ! F_22 () ) {
V_36 = V_6 -> V_42 ;
goto V_43;
}
V_40 = F_23 ( V_44 ) ;
if ( V_40 == V_45 ) {
V_36 = V_6 -> V_42 ;
goto V_43;
}
V_10 = F_6 ( V_8 ) ;
V_37 = V_10 -> V_16 ;
V_38 = V_39 = F_24 ( V_46 ) ;
if ( ( V_38 == V_31 ) &&
( V_37 > V_28 ) )
V_38 = V_28 ;
if ( V_38 != V_39 )
F_10 ( V_46 , V_38 ) ;
V_36 = F_18 ( V_6 , V_8 ) ;
V_43:
V_6 -> V_47 = V_36 ;
V_41 = F_5 ( V_6 , V_36 ) ;
if ( V_38 != V_39 )
F_10 ( V_46 , V_39 ) ;
return V_41 ;
}
void F_25 ( struct V_48 * V_49 )
{
int V_50 ;
if ( ! V_49 )
return;
for ( V_50 = 0 ; V_50 < V_35 ; V_50 ++ ) {
V_51 [ V_50 ] . V_33 = V_49 [ V_50 ] . V_33 ;
V_51 [ V_50 ] . V_52 =
V_49 [ V_50 ] . V_52 ;
V_51 [ V_50 ] . V_53 =
V_49 [ V_50 ] . V_53 ;
}
return;
}
static inline struct V_9 * F_26 (
struct V_5 * V_6 ,
int V_34 , const char * V_54 )
{
struct V_9 * V_10 = & V_55 [ V_34 ] ;
struct V_7 * V_8 = & V_6 -> V_20 [ V_34 ] ;
V_8 -> V_52 = V_51 [ V_34 ] . V_52 ;
V_8 -> V_53 = V_51 [ V_34 ] . V_53 ;
V_8 -> V_56 = V_57 ;
V_8 -> V_58 = F_21 ;
V_10 -> V_33 = V_51 [ V_34 ] . V_33 ;
sprintf ( V_8 -> V_59 , L_1 , V_34 + 1 ) ;
strncpy ( V_8 -> V_60 , V_54 , V_61 ) ;
F_27 ( V_8 , V_10 ) ;
return V_10 ;
}
int T_2 F_28 ( void )
{
struct V_5 * V_6 ;
struct V_9 * V_10 ;
V_17 = F_29 ( L_2 ) ;
V_18 = F_29 ( L_3 ) ;
V_46 = F_29 ( L_4 ) ;
V_44 = F_29 ( L_5 ) ;
F_30 ( & V_62 ) ;
V_6 = & F_31 ( V_63 , F_32 () ) ;
V_10 = F_26 ( V_6 , 0 , L_6 ) ;
( & V_6 -> V_20 [ 0 ] ) -> V_58 = F_5 ;
V_6 -> V_42 = & V_6 -> V_20 [ 0 ] ;
V_10 -> V_33 = 1 ;
V_10 -> V_15 = V_45 ;
V_10 -> V_16 = V_45 ;
V_10 = F_26 ( V_6 , 1 , L_6 ) ;
V_10 -> V_15 = V_45 ;
V_10 -> V_16 = V_45 ;
V_10 = F_26 ( V_6 , 2 , L_7 ) ;
V_10 -> V_15 = V_28 ;
V_10 -> V_16 = V_45 ;
V_10 = F_26 ( V_6 , 3 , L_8 ) ;
V_10 -> V_15 = V_31 ;
V_10 -> V_16 = V_45 ;
V_10 = F_26 ( V_6 , 4 , L_9 ) ;
V_10 -> V_15 = V_28 ;
V_10 -> V_16 = V_28 ;
V_10 = F_26 ( V_6 , 5 , L_10 ) ;
V_10 -> V_15 = V_31 ;
V_10 -> V_16 = V_28 ;
V_10 = F_26 ( V_6 , 6 , L_11 ) ;
if ( F_19 ( V_32 ) ) {
V_10 -> V_33 = 0 ;
F_33 ( L_12 ,
V_64 ) ;
}
V_10 -> V_15 = V_31 ;
V_10 -> V_16 = V_31 ;
V_6 -> V_65 = V_35 ;
if ( F_34 ( V_6 ) ) {
F_35 ( V_66 L_13 ,
V_64 ) ;
return - V_67 ;
}
return 0 ;
}
int T_2 F_28 ( void )
{
return 0 ;
}
