static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_1 , V_7 -> V_8 . V_1 ) ;
}
static T_1 F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_1 , V_7 -> V_8 . V_9 ) ;
}
static T_1 F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_2 , V_7 -> V_10 -> V_11 ( V_7 ) ) ;
}
static T_1 F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_3 ,
V_7 -> V_8 . V_1 , V_7 -> V_8 . V_9 ) ;
}
static T_1 F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
unsigned int V_12 ;
T_1 V_13 = 0 ;
for ( V_12 = 0 ; V_12 < sizeof( V_7 -> V_14 ) * 8 ; V_12 ++ )
V_13 += sprintf ( V_5 + V_13 , L_4 ,
F_7 ( V_7 , V_12 ) ? '1' : '0' ) ;
V_13 += sprintf ( V_5 + V_13 , L_5 ) ;
return V_13 ;
}
static inline int F_8 ( const struct V_6 * V_7 ,
const struct V_15 * V_8 )
{
if ( V_8 -> V_1 != V_7 -> V_8 . V_1 && V_8 -> V_1 != V_16 )
return 0 ;
return V_8 -> V_9 == V_16 || V_8 -> V_9 == V_7 -> V_8 . V_9 ;
}
static int F_9 ( struct V_1 * V_17 , struct V_18 * V_19 )
{
unsigned int V_12 ;
struct V_6 * V_7 = F_2 ( V_17 ) ;
const struct V_15 * V_20 ;
V_20 = F_10 ( V_19 ) -> V_21 ;
for ( V_12 = 0 ; V_20 [ V_12 ] . V_1 ; V_12 ++ )
if ( F_8 ( V_7 , & V_20 [ V_12 ] ) )
return 1 ;
return 0 ;
}
static int F_11 ( struct V_1 * V_17 , struct V_22 * V_23 )
{
struct V_6 * V_7 = F_2 ( V_17 ) ;
return F_12 ( V_23 , L_6 ,
V_7 -> V_8 . V_1 , V_7 -> V_8 . V_9 ) ;
}
void F_13 ( const struct V_6 * V_24 ,
unsigned int V_25 )
{
unsigned int V_12 ;
struct V_26 * V_27 = F_10 ( V_24 -> V_7 . V_28 ) ;
for ( V_12 = 0 ; V_12 < V_27 -> V_29 ; V_12 ++ )
if ( V_27 -> V_30 [ V_12 ] == V_25 )
return;
if ( V_27 -> V_31 ) {
for ( V_12 = 0 ; V_12 < V_27 -> V_32 ; V_12 ++ )
if ( V_27 -> V_31 [ V_12 ] == V_25 )
return;
}
F_14 () ;
}
static void F_15 ( struct V_6 * V_7 )
{
struct V_26 * V_27 = F_10 ( V_7 -> V_7 . V_28 ) ;
if ( ! V_7 -> V_33 )
V_7 -> V_34 = true ;
else if ( V_27 && V_27 -> V_35 )
V_27 -> V_35 ( V_7 ) ;
}
void F_16 ( struct V_6 * V_7 )
{
unsigned long V_36 ;
F_17 ( & V_7 -> V_37 , V_36 ) ;
F_15 ( V_7 ) ;
F_18 ( & V_7 -> V_37 , V_36 ) ;
}
void F_19 ( struct V_6 * V_7 )
{
F_20 ( & V_7 -> V_37 ) ;
V_7 -> V_33 = false ;
F_21 ( & V_7 -> V_37 ) ;
}
void F_22 ( struct V_6 * V_7 )
{
F_20 ( & V_7 -> V_37 ) ;
V_7 -> V_33 = true ;
if ( V_7 -> V_34 )
F_15 ( V_7 ) ;
V_7 -> V_34 = false ;
F_21 ( & V_7 -> V_37 ) ;
}
void F_23 ( struct V_6 * V_7 , unsigned int V_38 )
{
V_7 -> V_10 -> V_39 ( V_7 , V_7 -> V_10 -> V_11 ( V_7 ) | V_38 ) ;
}
int F_24 ( struct V_6 * V_7 )
{
int V_40 = V_7 -> V_10 -> V_41 ( V_7 ) ;
unsigned V_38 ;
if ( V_40 )
return V_40 ;
if ( ! F_25 ( V_7 , V_42 ) )
return 0 ;
F_23 ( V_7 , V_43 ) ;
V_38 = V_7 -> V_10 -> V_11 ( V_7 ) ;
if ( ! ( V_38 & V_43 ) ) {
F_26 ( & V_7 -> V_7 , L_7 ,
V_38 ) ;
return - V_44 ;
}
return 0 ;
}
static int F_27 ( struct V_1 * V_2 )
{
int V_45 , V_12 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_26 * V_27 = F_10 ( V_7 -> V_7 . V_28 ) ;
T_2 V_46 ;
T_2 V_47 ;
T_2 V_48 ;
F_23 ( V_7 , V_49 ) ;
V_46 = V_7 -> V_10 -> V_50 ( V_7 ) ;
V_47 = 0 ;
for ( V_12 = 0 ; V_12 < V_27 -> V_29 ; V_12 ++ ) {
unsigned int V_51 = V_27 -> V_30 [ V_12 ] ;
F_28 ( V_51 >= 64 ) ;
V_47 |= ( 1ULL << V_51 ) ;
}
if ( V_27 -> V_31 ) {
V_48 = 0 ;
for ( V_12 = 0 ; V_12 < V_27 -> V_32 ; V_12 ++ ) {
unsigned int V_51 = V_27 -> V_31 [ V_12 ] ;
F_28 ( V_51 >= 64 ) ;
V_48 |= ( 1ULL << V_51 ) ;
}
} else {
V_48 = V_47 ;
}
if ( V_46 & ( 1ULL << V_42 ) )
V_7 -> V_14 = V_47 & V_46 ;
else
V_7 -> V_14 = V_48 & V_46 ;
for ( V_12 = V_52 ; V_12 < V_53 ; V_12 ++ )
if ( V_46 & ( 1ULL << V_12 ) )
F_29 ( V_7 , V_12 ) ;
if ( V_27 -> V_54 ) {
V_45 = V_27 -> V_54 ( V_7 ) ;
if ( V_45 )
goto V_45;
}
V_45 = F_24 ( V_7 ) ;
if ( V_45 )
goto V_45;
V_45 = V_27 -> V_55 ( V_7 ) ;
if ( V_45 )
goto V_45;
if ( ! ( V_7 -> V_10 -> V_11 ( V_7 ) & V_56 ) )
F_30 ( V_7 ) ;
if ( V_27 -> V_57 )
V_27 -> V_57 ( V_7 ) ;
F_22 ( V_7 ) ;
return 0 ;
V_45:
F_23 ( V_7 , V_58 ) ;
return V_45 ;
}
static int F_31 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_26 * V_27 = F_10 ( V_7 -> V_7 . V_28 ) ;
F_19 ( V_7 ) ;
V_27 -> remove ( V_7 ) ;
F_32 ( V_7 -> V_10 -> V_11 ( V_7 ) ) ;
F_23 ( V_7 , V_59 ) ;
return 0 ;
}
int F_33 ( struct V_26 * V_28 )
{
F_28 ( V_28 -> V_29 && ! V_28 -> V_30 ) ;
V_28 -> V_28 . V_60 = & V_61 ;
return F_34 ( & V_28 -> V_28 ) ;
}
void F_35 ( struct V_26 * V_28 )
{
F_36 ( & V_28 -> V_28 ) ;
}
int F_37 ( struct V_6 * V_7 )
{
int V_45 ;
V_7 -> V_7 . V_60 = & V_61 ;
V_45 = F_38 ( & V_62 , 0 , 0 , V_63 ) ;
if ( V_45 < 0 )
goto V_64;
V_7 -> V_65 = V_45 ;
F_39 ( & V_7 -> V_7 , L_8 , V_7 -> V_65 ) ;
F_40 ( & V_7 -> V_37 ) ;
V_7 -> V_33 = false ;
V_7 -> V_34 = false ;
V_7 -> V_10 -> V_66 ( V_7 ) ;
F_23 ( V_7 , V_59 ) ;
F_41 ( & V_7 -> V_67 ) ;
V_45 = F_42 ( & V_7 -> V_7 ) ;
V_64:
if ( V_45 )
F_23 ( V_7 , V_58 ) ;
return V_45 ;
}
void F_43 ( struct V_6 * V_7 )
{
int V_65 = V_7 -> V_65 ;
F_44 ( & V_7 -> V_7 ) ;
F_45 ( & V_62 , V_65 ) ;
}
int F_46 ( struct V_6 * V_7 )
{
struct V_26 * V_27 = F_10 ( V_7 -> V_7 . V_28 ) ;
F_19 ( V_7 ) ;
V_7 -> V_68 = V_7 -> V_10 -> V_11 ( V_7 ) & V_58 ;
if ( V_27 && V_27 -> V_69 )
return V_27 -> V_69 ( V_7 ) ;
return 0 ;
}
int F_47 ( struct V_6 * V_7 )
{
struct V_26 * V_27 = F_10 ( V_7 -> V_7 . V_28 ) ;
int V_40 ;
V_7 -> V_10 -> V_66 ( V_7 ) ;
F_23 ( V_7 , V_59 ) ;
if ( V_7 -> V_68 )
F_23 ( V_7 , V_58 ) ;
if ( ! V_27 )
return 0 ;
F_23 ( V_7 , V_49 ) ;
V_40 = F_24 ( V_7 ) ;
if ( V_40 )
goto V_45;
if ( V_27 -> V_70 ) {
V_40 = V_27 -> V_70 ( V_7 ) ;
if ( V_40 )
goto V_45;
}
F_23 ( V_7 , V_56 ) ;
F_22 ( V_7 ) ;
return 0 ;
V_45:
F_23 ( V_7 , V_58 ) ;
return V_40 ;
}
static int F_48 ( void )
{
if ( F_49 ( & V_61 ) != 0 )
F_50 ( L_9 ) ;
return 0 ;
}
static void T_3 F_51 ( void )
{
F_52 ( & V_61 ) ;
F_53 ( & V_62 ) ;
}
