void
F_1 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_3 & V_4 ) ) {
struct V_5 * V_6 = V_2 -> V_7 ;
V_2 -> V_3 |= V_4 ;
if ( V_6 ) {
F_2 ( V_6 , V_2 ) ;
if ( V_6 -> V_8 == V_9 )
F_3 ( V_6 ) ;
}
F_4 ( & V_2 -> V_10 ) ;
}
if ( V_2 -> V_11 ) {
F_5 ( V_12 , L_1 , V_2 ) ;
return;
}
F_5 ( V_12 , L_2 , V_2 ) ;
if ( V_2 -> V_13 ) {
int V_14 = F_6 ( V_2 -> V_10 . V_15 ) ;
F_7 ( * V_2 -> V_13 -> V_16 [ V_14 ] > 0 ) ;
( * V_2 -> V_13 -> V_16 [ V_14 ] ) -- ;
}
F_7 ( ! F_8 ( & V_2 -> V_17 ) ) ;
F_9 ( & V_2 -> V_17 ) ;
F_10 ( V_2 ) ;
}
static int
F_11 ( struct V_1 * V_18 , struct V_19 * V_20 , int V_21 )
{
int V_22 ;
unsigned int V_23 ;
int V_24 = 0 ;
V_18 -> V_7 = NULL ;
V_18 -> V_25 = V_20 -> V_26 ;
V_18 -> V_27 = 0 ;
V_18 -> V_28 = V_20 -> V_29 ;
V_18 -> V_30 = V_20 -> V_31 ;
V_18 -> V_32 = V_20 -> V_33 ;
V_18 -> V_13 = NULL ;
V_18 -> V_34 = V_20 -> V_35 ;
V_18 -> V_11 = 0 ;
V_18 -> V_3 = ( V_21 == V_9 ) ? V_36 : 0 ;
if ( V_20 -> V_31 & V_37 ) {
if ( V_20 -> V_31 & V_38 )
return - V_39 ;
V_23 = V_20 -> V_40 ;
V_18 -> V_41 = V_20 -> V_40 ;
memcpy ( V_18 -> V_42 . V_43 , V_20 -> V_26 ,
V_23 * sizeof( V_18 -> V_42 . V_43 [ 0 ] ) ) ;
for ( V_22 = 0 ; V_22 < ( int ) V_23 ; V_22 ++ ) {
if ( V_18 -> V_42 . V_43 [ V_22 ] . V_44 <= 0 )
return - V_39 ;
V_24 += V_18 -> V_42 . V_43 [ V_22 ] . V_44 ;
}
V_18 -> V_45 = V_24 ;
if ( ( V_20 -> V_31 & V_46 ) &&
( V_20 -> V_29 < 0 ||
V_20 -> V_29 > V_24 ) )
return - V_39 ;
} else if ( V_20 -> V_31 & V_38 ) {
V_23 = V_20 -> V_40 ;
V_18 -> V_41 = V_20 -> V_40 ;
memcpy ( V_18 -> V_42 . V_47 , V_20 -> V_26 ,
V_23 * sizeof( V_18 -> V_42 . V_47 [ 0 ] ) ) ;
for ( V_22 = 0 ; V_22 < ( int ) V_23 ; V_22 ++ ) {
if ( V_18 -> V_42 . V_47 [ V_22 ] . V_48 +
V_18 -> V_42 . V_47 [ V_22 ] . V_49 > V_50 )
return - V_39 ;
V_24 += V_18 -> V_42 . V_47 [ V_22 ] . V_49 ;
}
V_18 -> V_45 = V_24 ;
if ( ( V_20 -> V_31 & V_46 ) &&
( V_20 -> V_29 < 0 ||
V_20 -> V_29 > V_24 ) )
return - V_39 ;
} else {
V_18 -> V_45 = V_20 -> V_40 ;
V_23 = 1 ;
V_18 -> V_41 = 1 ;
V_18 -> V_42 . V_43 [ 0 ] . V_51 = V_20 -> V_26 ;
V_18 -> V_42 . V_43 [ 0 ] . V_44 = V_20 -> V_40 ;
if ( ( V_20 -> V_31 & V_46 ) &&
( V_20 -> V_29 < 0 ||
V_20 -> V_29 > ( int ) V_20 -> V_40 ) )
return - V_39 ;
}
return 0 ;
}
static int
F_12 ( struct V_1 * V_2 , struct V_52 V_53 , int V_14 )
{
struct V_54 * V_55 = V_56 . V_57 [ V_14 ] ;
if ( ! F_13 ( V_53 ) ) {
V_2 -> V_13 = F_14 ( & V_53 ) ;
if ( ! V_2 -> V_13 )
return - V_58 ;
( * V_2 -> V_13 -> V_16 [ V_14 ] ) ++ ;
}
F_15 ( V_55 , & V_2 -> V_10 ) ;
F_7 ( F_8 ( & V_2 -> V_17 ) ) ;
F_16 ( & V_2 -> V_17 , & V_55 -> V_59 ) ;
return 0 ;
}
void
F_17 ( struct V_1 * V_18 , struct V_19 * V_20 )
{
V_20 -> V_26 = V_18 -> V_25 ;
V_20 -> V_40 = ! ( V_18 -> V_30 &
( V_37 | V_38 ) ) ?
V_18 -> V_45 : V_18 -> V_41 ;
V_20 -> V_35 = V_18 -> V_34 ;
V_20 -> V_29 = V_18 -> V_28 ;
V_20 -> V_31 = V_18 -> V_30 ;
V_20 -> V_33 = V_18 -> V_32 ;
F_18 ( & V_20 -> V_53 , V_18 -> V_13 ) ;
}
static int
F_19 ( struct V_19 * V_20 )
{
if ( ! V_20 -> V_26 && V_20 -> V_40 ) {
F_20 ( L_3 ,
V_20 -> V_40 ) ;
return - V_39 ;
}
if ( ( V_20 -> V_31 & ( V_38 | V_37 ) ) &&
V_20 -> V_40 > V_60 ) {
F_20 ( L_4 ,
V_20 -> V_40 , V_60 ) ;
return - V_39 ;
}
return 0 ;
}
int
F_21 ( struct V_61 V_62 , struct V_19 V_20 ,
enum V_63 V_21 , struct V_64 * V_65 )
{
F_22 ( V_66 ) ;
F_22 ( V_67 ) ;
struct V_5 * V_6 ;
struct V_1 * V_2 ;
int V_14 ;
int V_68 ;
F_7 ( V_56 . V_69 > 0 ) ;
if ( F_19 ( & V_20 ) )
return - V_39 ;
if ( ! ( V_20 . V_31 & ( V_70 | V_71 ) ) ) {
F_20 ( L_5 ) ;
return - V_39 ;
}
V_2 = F_23 ( & V_20 ) ;
if ( ! V_2 )
return - V_72 ;
V_68 = F_11 ( V_2 , & V_20 , V_21 ) ;
if ( V_68 )
goto V_73;
V_14 = F_6 ( V_62 . V_74 ) ;
F_24 ( V_14 ) ;
V_6 = F_25 ( & V_62 ) ;
if ( ! V_6 )
V_68 = - V_58 ;
else if ( V_6 -> V_75 )
V_68 = - V_76 ;
else
V_68 = F_12 ( V_2 , V_20 . V_53 , V_14 ) ;
if ( V_68 )
goto V_77;
F_26 ( V_6 , V_2 , & V_66 , & V_67 ) ;
F_27 ( V_65 , V_2 ) ;
F_28 ( V_14 ) ;
F_29 ( & V_67 , L_6 ) ;
F_30 ( & V_66 ) ;
return 0 ;
V_77:
F_28 ( V_14 ) ;
V_73:
F_10 ( V_2 ) ;
return V_68 ;
}
int
F_31 ( struct V_19 V_20 , enum V_63 V_21 ,
struct V_64 * V_65 )
{
struct V_1 * V_2 ;
int V_14 ;
int V_68 ;
F_7 ( V_56 . V_69 > 0 ) ;
if ( F_19 ( & V_20 ) )
return - V_39 ;
if ( ( V_20 . V_31 & ( V_70 | V_71 ) ) ) {
F_20 ( L_7 ) ;
return - V_39 ;
}
V_2 = F_23 ( & V_20 ) ;
if ( ! V_2 )
return - V_72 ;
V_68 = F_11 ( V_2 , & V_20 , V_21 ) ;
if ( V_68 )
goto V_73;
V_14 = F_32 () ;
V_68 = F_12 ( V_2 , V_20 . V_53 , V_14 ) ;
if ( V_68 )
goto V_77;
F_27 ( V_65 , V_2 ) ;
F_28 ( V_14 ) ;
return 0 ;
V_77:
F_28 ( V_14 ) ;
V_73:
F_10 ( V_2 ) ;
return V_68 ;
}
int
F_33 ( struct V_64 V_78 )
{
struct V_79 V_80 ;
struct V_1 * V_2 ;
int V_14 ;
F_7 ( V_56 . V_69 > 0 ) ;
V_14 = F_6 ( V_78 . V_74 ) ;
F_24 ( V_14 ) ;
V_2 = F_34 ( & V_78 ) ;
if ( ! V_2 ) {
F_28 ( V_14 ) ;
return - V_58 ;
}
V_2 -> V_3 |= V_81 ;
if ( V_2 -> V_13 && ! V_2 -> V_11 ) {
F_35 ( V_2 , & V_80 ) ;
F_36 ( V_2 -> V_13 , & V_80 ) ;
}
F_1 ( V_2 ) ;
F_28 ( V_14 ) ;
return 0 ;
}
