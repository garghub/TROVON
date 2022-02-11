static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( F_3 ( V_3 ) , struct V_1 ,
V_4 ) ;
}
static int F_4 ( struct V_2 * V_5 )
{
struct V_1 * V_6 = F_1 ( V_5 ) ;
if ( F_5 ( V_6 -> V_7 [ V_6 -> V_8 ] ) )
return 1 ;
F_6 ( V_6 -> V_9 , L_1 ) ;
return 0 ;
}
static void F_7 ( struct V_1 * V_6 )
{
if ( V_6 -> V_7 [ V_6 -> V_8 ] >= 0 ) {
struct V_2 * V_5 = F_8 ( & V_6 -> V_4 ) ;
int V_10 = 1000000 ;
while ( -- V_10 && ! F_4 ( V_5 ) )
F_9 () ;
if ( ! V_10 )
F_10 ( V_6 -> V_9 , L_2 ) ;
} else {
F_11 ( 100 ) ;
}
}
static void F_12 ( struct V_2 * V_5 , int V_11 , unsigned int V_12 )
{
struct V_13 * V_4 = F_3 ( V_5 ) ;
struct V_1 * V_6 = F_1 ( V_5 ) ;
T_1 V_14 ;
if ( ! ( V_12 & V_6 -> V_15 ) ) {
F_13 ( & V_6 -> V_16 ) ;
if ( V_11 == V_17 )
return;
V_6 -> V_15 = V_12 & ( V_18 | V_19 ) ;
}
if ( V_12 & V_20 ) {
if ( V_12 & V_18 )
F_14 ( & V_6 -> V_16 , V_6 -> V_21 ) ;
else if ( V_12 & V_19 )
F_14 ( & V_6 -> V_16 , V_6 -> V_22 ) ;
}
V_14 = ( V_11 << ( 32 - V_6 -> V_16 . V_23 ) ) |
V_6 -> V_24 [ V_6 -> V_8 ] ;
F_15 ( & V_6 -> V_16 , V_4 -> V_25 , V_14 ) ;
if ( V_6 -> V_26 & V_27 )
F_7 ( V_6 ) ;
}
static void F_16 ( struct V_2 * V_5 , int V_28 )
{
struct V_13 * V_4 = F_3 ( V_5 ) ;
struct V_1 * V_6 = F_1 ( V_5 ) ;
if ( V_28 == - 1 ) {
V_4 -> V_29 ( V_5 , V_17 , 0 | V_20 ) ;
} else if ( V_28 >= 0 && V_28 < V_30 ) {
V_6 -> V_8 = V_28 ;
V_4 -> V_25 = V_6 -> V_31 + V_6 -> V_24 [ V_28 ] ;
V_4 -> V_32 = V_4 -> V_25 ;
} else {
F_17 () ;
}
}
static T_2 F_18 ( struct V_2 * V_5 )
{
struct V_1 * V_6 = F_1 ( V_5 ) ;
return F_19 ( V_6 -> V_4 . V_25 ) ;
}
static void F_20 ( struct V_2 * V_5 , T_2 * V_33 , int V_34 )
{
struct V_1 * V_6 = F_1 ( V_5 ) ;
int V_35 ;
for ( V_35 = 0 ; V_35 < V_34 ; V_35 ++ )
V_33 [ V_35 ] = F_19 ( V_6 -> V_4 . V_25 ) ;
}
static void F_21 ( struct V_2 * V_5 , const T_2 * V_33 , int V_34 )
{
struct V_1 * V_6 = F_1 ( V_5 ) ;
int V_35 ;
for ( V_35 = 0 ; V_35 < V_34 ; V_35 ++ ) {
F_22 ( V_6 -> V_4 . V_32 , V_33 [ V_35 ] ) ;
if ( V_6 -> V_26 & V_36 )
F_7 ( V_6 ) ;
}
if ( V_6 -> V_26 & V_37 )
F_7 ( V_6 ) ;
}
static int F_23 ( struct V_1 * V_6 ,
const struct V_38 * V_39 ,
const struct V_40 * V_41 )
{
struct V_2 * V_5 = F_8 ( & V_6 -> V_4 ) ;
int V_42 ;
struct V_38 * V_43 ;
V_6 -> V_4 . V_25 = V_6 -> V_31 ;
V_6 -> V_4 . V_32 = V_6 -> V_31 ;
V_6 -> V_4 . V_29 = F_12 ;
V_6 -> V_4 . V_44 = V_6 -> V_44 ;
V_6 -> V_4 . V_45 = F_18 ;
V_6 -> V_4 . V_46 = F_20 ;
V_6 -> V_4 . V_47 = F_21 ;
V_6 -> V_4 . V_48 . V_49 = V_50 ;
V_6 -> V_4 . V_48 . V_51 = V_52 ;
if ( V_6 -> V_53 > 1 )
V_6 -> V_4 . V_54 = F_16 ;
if ( V_6 -> V_7 [ 0 ] >= 0 )
V_6 -> V_4 . V_55 = F_4 ;
V_5 -> V_9 . V_56 = V_6 -> V_9 ;
V_43 = F_24 ( V_39 , NULL ) ;
if ( ! V_43 )
return - V_57 ;
F_25 ( & V_6 -> V_4 , V_43 ) ;
V_5 -> V_58 = F_26 ( V_59 , L_3 , ( V_60 ) V_41 -> V_61 ,
V_43 -> V_58 ) ;
if ( ! V_5 -> V_58 ) {
V_42 = - V_62 ;
goto V_63;
}
V_42 = F_27 ( V_5 , V_6 -> V_53 ) ;
if ( V_42 )
goto V_63;
V_42 = F_28 ( V_5 , NULL , 0 ) ;
V_63:
F_29 ( V_43 ) ;
if ( V_42 )
F_30 ( V_5 -> V_58 ) ;
return V_42 ;
}
static int F_31 ( struct V_64 * V_65 )
{
struct V_1 * V_6 ;
struct V_40 V_41 ;
const T_3 * V_66 ;
int V_7 ;
int V_42 ;
int V_67 ;
int V_35 ;
V_6 = F_32 ( sizeof( * V_6 ) , V_59 ) ;
if ( ! V_6 )
return - V_62 ;
V_42 = F_33 ( V_65 -> V_9 . V_68 , 0 , & V_41 ) ;
if ( V_42 ) {
F_10 ( & V_65 -> V_9 , L_4 ) ;
goto V_69;
}
V_42 = F_34 ( V_41 . V_61 , & V_6 -> V_16 ) ;
if ( V_42 ) {
F_10 ( & V_65 -> V_9 , L_5 ) ;
goto V_69;
}
V_66 = F_35 ( V_65 -> V_9 . V_68 , L_6 ,
& V_67 ) ;
if ( ! V_66 || V_67 != sizeof( V_70 ) ) {
F_10 ( & V_65 -> V_9 , L_7 ) ;
V_42 = - V_71 ;
goto V_69;
}
V_6 -> V_21 = * V_66 ;
V_66 = F_35 ( V_65 -> V_9 . V_68 , L_8 , & V_67 ) ;
if ( ! V_66 || V_67 != sizeof( V_70 ) ) {
F_10 ( & V_65 -> V_9 , L_9 ) ;
V_42 = - V_71 ;
goto V_69;
}
V_6 -> V_22 = * V_66 ;
V_66 = F_35 ( V_65 -> V_9 . V_68 ,
L_10 , & V_67 ) ;
if ( V_66 && ( V_67 / sizeof( V_70 ) ) > 0 ) {
V_6 -> V_53 = V_67 / sizeof( V_70 ) ;
if ( V_6 -> V_53 >= V_30 ) {
F_10 ( & V_65 -> V_9 , L_11 ) ;
goto V_69;
}
for ( V_35 = 0 ; V_35 < V_6 -> V_53 ; V_35 ++ )
V_6 -> V_24 [ V_35 ] = F_36 ( V_66 [ V_35 ] ) ;
} else {
V_6 -> V_53 = 1 ;
}
for ( V_35 = 0 ; V_35 < V_6 -> V_53 ; V_35 ++ ) {
V_6 -> V_7 [ V_35 ] = - 1 ;
V_7 = F_37 ( V_65 -> V_9 . V_68 , V_35 ) ;
if ( V_7 >= 0 ) {
V_42 = F_38 ( V_7 , F_39 ( & V_65 -> V_9 ) ) ;
if ( V_42 ) {
F_10 ( & V_65 -> V_9 ,
L_12 , V_35 ) ;
goto V_72;
}
F_40 ( V_7 ) ;
V_6 -> V_7 [ V_35 ] = V_7 ;
} else if ( V_7 == - V_71 ) {
F_10 ( & V_65 -> V_9 , L_13 , V_35 ) ;
goto V_72;
}
}
V_66 = F_35 ( V_65 -> V_9 . V_68 , L_14 , NULL ) ;
if ( V_66 )
V_6 -> V_44 = F_41 ( V_66 ) ;
else
V_6 -> V_44 = 50 ;
V_66 = F_35 ( V_65 -> V_9 . V_68 , L_15 , & V_67 ) ;
if ( V_66 && V_67 == sizeof( V_70 ) )
V_6 -> V_26 = F_41 ( V_66 ) ;
else
V_6 -> V_26 = V_27 |
V_36 ;
V_6 -> V_31 = F_42 ( & V_65 -> V_9 , V_41 . V_61 ,
F_43 ( & V_41 ) ) ;
if ( ! V_6 -> V_31 ) {
V_42 = - V_62 ;
goto V_72;
}
V_6 -> V_9 = & V_65 -> V_9 ;
V_6 -> V_15 = V_19 ;
V_42 = F_23 ( V_6 , V_65 -> V_9 . V_68 , & V_41 ) ;
if ( V_42 )
goto V_72;
F_44 ( & V_65 -> V_9 , V_6 ) ;
return 0 ;
V_72:
for ( V_35 = 0 ; V_35 < V_6 -> V_53 ; V_35 ++ ) {
if ( V_6 -> V_7 [ V_35 ] < 0 )
break;
F_45 ( V_6 -> V_7 [ V_35 ] ) ;
}
V_69:
F_30 ( V_6 ) ;
return V_42 ;
}
static int F_46 ( struct V_64 * V_65 )
{
struct V_1 * V_6 = F_47 ( & V_65 -> V_9 ) ;
struct V_2 * V_5 = F_8 ( & V_6 -> V_4 ) ;
int V_35 ;
F_48 ( V_5 ) ;
F_30 ( V_5 -> V_58 ) ;
for ( V_35 = 0 ; V_35 < V_6 -> V_53 ; V_35 ++ ) {
if ( V_6 -> V_7 [ V_35 ] < 0 )
break;
F_45 ( V_6 -> V_7 [ V_35 ] ) ;
}
F_30 ( V_6 ) ;
return 0 ;
}
