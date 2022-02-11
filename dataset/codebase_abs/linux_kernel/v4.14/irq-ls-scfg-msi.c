static int T_1 F_1 ( char * V_1 )
{
if ( V_1 && strncmp ( V_1 , L_1 , 11 ) == 0 )
V_2 = 0 ;
else
V_2 = 1 ;
return 0 ;
}
static void F_2 ( struct V_3 * V_4 , struct V_5 * V_6 )
{
struct V_7 * V_8 = F_3 ( V_4 ) ;
V_6 -> V_9 = F_4 ( V_8 -> V_10 ) ;
V_6 -> V_11 = F_5 ( V_8 -> V_10 ) ;
V_6 -> V_4 = V_4 -> V_12 ;
if ( V_2 )
V_6 -> V_4 |= F_6 ( V_4 -> V_13 -> V_14 ) ;
}
static int F_7 ( struct V_3 * V_3 ,
const struct V_15 * V_16 , bool V_17 )
{
struct V_7 * V_8 = F_3 ( V_3 ) ;
T_2 V_18 ;
if ( ! V_2 )
return - V_19 ;
if ( ! V_17 )
V_18 = F_8 ( V_16 , V_20 ) ;
else
V_18 = F_6 ( V_16 ) ;
if ( V_18 >= V_8 -> V_21 )
return - V_19 ;
if ( V_8 -> V_22 [ V_18 ] . V_23 <= 0 ) {
F_9 ( L_2 , V_18 ) ;
return - V_19 ;
}
F_10 ( V_3 -> V_13 -> V_14 , V_16 ) ;
return V_24 ;
}
static int F_11 ( struct V_25 * V_26 ,
unsigned int V_27 ,
unsigned int V_28 ,
void * args )
{
struct V_7 * V_8 = V_26 -> V_29 ;
int V_30 , V_31 = 0 ;
F_12 ( V_28 != 1 ) ;
F_13 ( & V_8 -> V_32 ) ;
V_30 = F_14 ( V_8 -> V_33 , V_8 -> V_34 ) ;
if ( V_30 < V_8 -> V_34 )
F_15 ( V_30 , V_8 -> V_33 ) ;
else
V_31 = - V_35 ;
F_16 ( & V_8 -> V_32 ) ;
if ( V_31 )
return V_31 ;
F_17 ( V_26 , V_27 , V_30 ,
& V_36 , V_8 ,
V_37 , NULL , NULL ) ;
return 0 ;
}
static void F_18 ( struct V_25 * V_26 ,
unsigned int V_27 , unsigned int V_28 )
{
struct V_3 * V_38 = F_19 ( V_26 , V_27 ) ;
struct V_7 * V_8 = F_3 ( V_38 ) ;
int V_30 ;
V_30 = V_38 -> V_12 ;
if ( V_30 < 0 || V_30 >= V_8 -> V_34 ) {
F_20 ( L_3 , V_30 ) ;
return;
}
F_13 ( & V_8 -> V_32 ) ;
F_21 ( V_30 , V_8 -> V_33 ) ;
F_16 ( & V_8 -> V_32 ) ;
}
static void F_22 ( struct V_39 * V_40 )
{
struct V_41 * V_22 = F_23 ( V_40 ) ;
struct V_7 * V_8 = V_22 -> V_8 ;
unsigned long V_42 ;
int V_30 , V_43 , V_27 , V_12 ;
F_24 ( F_25 ( V_40 ) , V_40 ) ;
V_42 = F_26 ( V_22 -> V_44 ) ;
V_30 = V_22 -> V_45 ;
V_43 = V_22 -> V_46 + 1 ;
F_27 (pos, &val, size) {
V_12 = ( ( V_22 -> V_46 - V_30 ) << V_8 -> V_47 -> V_48 ) |
V_22 -> V_49 ;
V_27 = F_28 ( V_8 -> V_50 , V_12 ) ;
if ( V_27 )
F_29 ( V_27 ) ;
}
F_30 ( F_25 ( V_40 ) , V_40 ) ;
}
static int F_31 ( struct V_7 * V_8 )
{
V_8 -> V_50 = F_32 ( NULL ,
V_8 -> V_34 ,
& V_51 ,
V_8 ) ;
if ( ! V_8 -> V_50 ) {
F_33 ( & V_8 -> V_52 -> V_53 , L_4 ) ;
return - V_54 ;
}
V_8 -> V_55 = F_34 (
F_35 ( V_8 -> V_52 -> V_53 . V_56 ) ,
& V_57 ,
V_8 -> V_50 ) ;
if ( ! V_8 -> V_55 ) {
F_33 ( & V_8 -> V_52 -> V_53 , L_5 ) ;
F_36 ( V_8 -> V_50 ) ;
return - V_54 ;
}
return 0 ;
}
static int F_37 ( struct V_7 * V_8 , int V_58 )
{
struct V_41 * V_22 ;
int V_27 , V_59 , V_12 ;
V_27 = F_38 ( V_8 -> V_52 , V_58 ) ;
if ( V_27 <= 0 )
return - V_60 ;
V_22 = & V_8 -> V_22 [ V_58 ] ;
V_22 -> V_58 = V_58 ;
V_22 -> V_8 = V_8 ;
V_22 -> V_23 = V_27 ;
V_22 -> V_44 = V_8 -> V_61 + V_8 -> V_47 -> V_62 + 4 * V_58 ;
if ( V_8 -> V_47 -> V_63 == V_64 ) {
V_22 -> V_45 = 32 - ( ( V_22 -> V_58 + 1 ) *
V_64 ) ;
V_22 -> V_46 = V_22 -> V_45 +
V_64 - 1 ;
} else {
V_22 -> V_45 = 0 ;
V_22 -> V_46 = V_8 -> V_47 -> V_63 - 1 ;
}
F_39 ( V_22 -> V_23 ,
F_22 ,
V_22 ) ;
if ( V_2 ) {
F_40 ( V_22 -> V_23 , F_41 ( V_58 ) ) ;
V_22 -> V_49 = 0 ;
} else
V_22 -> V_49 = V_58 ;
if ( ! V_2 || V_22 -> V_58 == 0 ) {
for ( V_59 = 0 ; V_59 < V_8 -> V_47 -> V_63 ; V_59 ++ ) {
V_12 = V_59 << V_8 -> V_47 -> V_48 | V_22 -> V_58 ;
F_42 ( V_8 -> V_33 , V_12 , 1 ) ;
}
}
return 0 ;
}
static int F_43 ( struct V_41 * V_22 )
{
struct V_7 * V_8 = V_22 -> V_8 ;
int V_59 , V_12 ;
if ( V_22 -> V_23 > 0 )
F_39 ( V_22 -> V_23 , NULL , NULL ) ;
for ( V_59 = 0 ; V_59 < V_8 -> V_47 -> V_63 ; V_59 ++ ) {
V_12 = V_59 << V_8 -> V_47 -> V_48 | V_22 -> V_58 ;
F_44 ( V_8 -> V_33 , V_12 , 1 ) ;
}
return 0 ;
}
static int F_45 ( struct V_65 * V_52 )
{
const struct V_66 * V_67 ;
struct V_7 * V_8 ;
struct V_68 * V_69 ;
int V_59 , V_70 ;
V_67 = F_46 ( V_71 , & V_52 -> V_53 ) ;
if ( ! V_67 )
return - V_60 ;
V_8 = F_47 ( & V_52 -> V_53 , sizeof( * V_8 ) , V_72 ) ;
if ( ! V_8 )
return - V_54 ;
V_8 -> V_47 = (struct V_73 * ) V_67 -> V_4 ;
V_69 = F_48 ( V_52 , V_74 , 0 ) ;
V_8 -> V_61 = F_49 ( & V_52 -> V_53 , V_69 ) ;
if ( F_50 ( V_8 -> V_61 ) ) {
F_33 ( & V_52 -> V_53 , L_6 ) ;
return F_51 ( V_8 -> V_61 ) ;
}
V_8 -> V_10 = V_69 -> V_75 ;
V_8 -> V_52 = V_52 ;
F_52 ( & V_8 -> V_32 ) ;
V_8 -> V_34 = V_76 *
( 1 << V_8 -> V_47 -> V_48 ) ;
V_8 -> V_33 = F_53 ( & V_52 -> V_53 ,
F_54 ( V_8 -> V_34 ) ,
sizeof( * V_8 -> V_33 ) ,
V_72 ) ;
if ( ! V_8 -> V_33 )
return - V_54 ;
F_44 ( V_8 -> V_33 , 0 , V_8 -> V_34 ) ;
V_8 -> V_21 = F_55 ( V_52 -> V_53 . V_56 ) ;
if ( V_2 ) {
T_2 V_77 ;
V_77 = F_56 () ;
if ( V_8 -> V_21 >= V_77 )
V_8 -> V_21 = V_77 ;
else
V_2 = 0 ;
}
V_8 -> V_22 = F_53 ( & V_52 -> V_53 , V_8 -> V_21 ,
sizeof( * V_8 -> V_22 ) ,
V_72 ) ;
if ( ! V_8 -> V_22 )
return - V_54 ;
for ( V_59 = 0 ; V_59 < V_8 -> V_21 ; V_59 ++ )
F_37 ( V_8 , V_59 ) ;
V_70 = F_31 ( V_8 ) ;
if ( V_70 )
return V_70 ;
F_57 ( V_52 , V_8 ) ;
return 0 ;
}
static int F_58 ( struct V_65 * V_52 )
{
struct V_7 * V_8 = F_59 ( V_52 ) ;
int V_59 ;
for ( V_59 = 0 ; V_59 < V_8 -> V_21 ; V_59 ++ )
F_43 ( & V_8 -> V_22 [ V_59 ] ) ;
F_36 ( V_8 -> V_55 ) ;
F_36 ( V_8 -> V_50 ) ;
F_57 ( V_52 , NULL ) ;
return 0 ;
}
