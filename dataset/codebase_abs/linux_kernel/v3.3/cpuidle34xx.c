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
struct V_13 V_14 , V_15 , V_16 ;
T_1 V_17 = V_11 -> V_17 , V_18 = V_11 -> V_18 ;
int V_19 ;
F_7 ( & V_14 ) ;
F_8 () ;
F_9 () ;
F_10 ( V_20 , V_17 ) ;
F_10 ( V_21 , V_18 ) ;
if ( F_11 () || F_12 () )
goto V_22;
if ( V_9 == 0 ) {
F_13 ( V_20 , F_3 ) ;
F_13 ( V_21 , F_3 ) ;
}
if ( V_17 == V_23 )
F_14 () ;
F_15 () ;
if ( F_16 ( V_20 ) == V_23 )
F_17 () ;
if ( V_9 == 0 ) {
F_13 ( V_20 , F_1 ) ;
F_13 ( V_21 , F_1 ) ;
}
V_22:
F_7 ( & V_15 ) ;
V_16 = F_18 ( V_15 , V_14 ) ;
F_19 () ;
F_20 () ;
V_19 = V_16 . V_24 / V_25 + V_16 . V_26 * \
V_27 ;
V_6 -> V_28 = V_19 ;
return V_9 ;
}
static int F_21 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
int V_9 )
{
struct V_29 * V_30 = & V_6 -> V_12 [ V_9 ] ;
struct V_31 * V_32 = & V_8 -> V_33 [ V_9 ] ;
struct V_10 * V_11 = F_6 ( V_30 ) ;
T_1 V_34 = V_35 ;
T_1 V_36 = V_35 ;
int V_37 = - 1 ;
if ( V_38 ) {
V_34 = V_23 ;
if ( ! F_22 ( V_39 ) )
V_36 = V_23 ;
}
if ( ( V_11 -> V_40 ) &&
( V_11 -> V_17 >= V_34 ) &&
( V_11 -> V_18 >= V_36 ) ) {
return V_9 ;
} else {
int V_41 = V_42 - 1 ;
for (; V_41 >= 0 ; V_41 -- ) {
if ( & V_8 -> V_33 [ V_41 ] == V_32 ) {
V_37 = V_41 ;
break;
}
}
F_23 ( V_37 == - 1 ) ;
V_41 -- ;
for (; V_41 >= 0 ; V_41 -- ) {
V_11 = F_6 ( & V_6 -> V_12 [ V_41 ] ) ;
if ( ( V_11 -> V_40 ) &&
( V_11 -> V_17 >= V_34 ) &&
( V_11 -> V_18 >= V_36 ) ) {
V_37 = V_41 ;
break;
}
}
}
return V_37 ;
}
static int F_24 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
int V_9 )
{
int V_43 ;
T_1 V_44 , V_45 = 0 , V_46 = 0 , V_47 ;
struct V_10 * V_11 ;
int V_48 ;
V_47 = F_25 ( V_49 ) ;
if ( V_47 == V_50 ) {
V_43 = V_8 -> V_51 ;
goto V_52;
}
V_11 = F_6 ( & V_6 -> V_12 [ V_9 ] ) ;
V_44 = V_11 -> V_18 ;
V_45 = V_46 = F_26 ( V_53 ) ;
if ( ( V_45 == V_23 ) &&
( V_44 > V_35 ) )
V_45 = V_35 ;
if ( V_45 != V_46 )
F_10 ( V_53 , V_45 ) ;
V_43 = F_21 ( V_6 , V_8 , V_9 ) ;
V_52:
V_48 = F_5 ( V_6 , V_8 , V_43 ) ;
if ( V_45 != V_46 )
F_10 ( V_53 , V_46 ) ;
return V_48 ;
}
void F_27 ( struct V_54 * V_55 )
{
int V_56 ;
if ( ! V_55 )
return;
for ( V_56 = 0 ; V_56 < V_42 ; V_56 ++ ) {
V_57 [ V_56 ] . V_40 = V_55 [ V_56 ] . V_40 ;
V_57 [ V_56 ] . V_58 =
V_55 [ V_56 ] . V_58 ;
V_57 [ V_56 ] . V_59 =
V_55 [ V_56 ] . V_59 ;
}
return;
}
static inline void F_28 ( struct V_7 * V_8 ,
int V_41 , const char * V_60 )
{
struct V_31 * V_61 = & V_8 -> V_33 [ V_41 ] ;
V_61 -> V_58 = V_57 [ V_41 ] . V_58 ;
V_61 -> V_59 = V_57 [ V_41 ] . V_59 ;
V_61 -> V_62 = V_63 ;
V_61 -> V_64 = F_24 ;
sprintf ( V_61 -> V_65 , L_1 , V_41 + 1 ) ;
strncpy ( V_61 -> V_66 , V_60 , V_67 ) ;
}
static inline struct V_10 * F_29 (
struct V_5 * V_6 ,
int V_41 )
{
struct V_10 * V_11 = & V_68 [ V_41 ] ;
struct V_29 * V_69 = & V_6 -> V_12 [ V_41 ] ;
V_11 -> V_40 = V_57 [ V_41 ] . V_40 ;
F_30 ( V_69 , V_11 ) ;
return V_11 ;
}
int T_2 F_31 ( void )
{
struct V_5 * V_6 ;
struct V_7 * V_8 = & V_70 ;
struct V_10 * V_11 ;
V_20 = F_32 ( L_2 ) ;
V_21 = F_32 ( L_3 ) ;
V_53 = F_32 ( L_4 ) ;
V_49 = F_32 ( L_5 ) ;
V_8 -> V_51 = - 1 ;
V_6 = & F_33 ( V_71 , F_34 () ) ;
F_28 ( V_8 , 0 , L_6 ) ;
( & V_8 -> V_33 [ 0 ] ) -> V_64 = F_5 ;
V_8 -> V_51 = 0 ;
V_11 = F_29 ( V_6 , 0 ) ;
V_11 -> V_40 = 1 ;
V_11 -> V_17 = V_50 ;
V_11 -> V_18 = V_50 ;
F_28 ( V_8 , 1 , L_6 ) ;
V_11 = F_29 ( V_6 , 1 ) ;
V_11 -> V_17 = V_50 ;
V_11 -> V_18 = V_50 ;
F_28 ( V_8 , 2 , L_7 ) ;
V_11 = F_29 ( V_6 , 2 ) ;
V_11 -> V_17 = V_35 ;
V_11 -> V_18 = V_50 ;
F_28 ( V_8 , 3 , L_8 ) ;
V_11 = F_29 ( V_6 , 3 ) ;
V_11 -> V_17 = V_23 ;
V_11 -> V_18 = V_50 ;
F_28 ( V_8 , 4 , L_9 ) ;
V_11 = F_29 ( V_6 , 4 ) ;
V_11 -> V_17 = V_35 ;
V_11 -> V_18 = V_35 ;
F_28 ( V_8 , 5 , L_10 ) ;
V_11 = F_29 ( V_6 , 5 ) ;
V_11 -> V_17 = V_23 ;
V_11 -> V_18 = V_35 ;
F_28 ( V_8 , 6 , L_11 ) ;
V_11 = F_29 ( V_6 , 6 ) ;
if ( F_22 ( V_39 ) ) {
V_11 -> V_40 = 0 ;
F_35 ( L_12 ,
V_72 ) ;
}
V_11 -> V_17 = V_23 ;
V_11 -> V_18 = V_23 ;
V_8 -> V_73 = V_42 ;
F_36 ( & V_70 ) ;
V_6 -> V_73 = V_42 ;
if ( F_37 ( V_6 ) ) {
F_38 ( V_74 L_13 ,
V_72 ) ;
return - V_75 ;
}
return 0 ;
}
int T_2 F_31 ( void )
{
return 0 ;
}
