static void F_1 ( T_1 * V_1 , T_2 V_2 , T_3 V_3 , T_4 type )
{
V_1 -> V_4 = 7 ;
V_1 -> V_5 . V_6 = type ;
V_1 -> V_5 . V_7 = F_2 ( V_2 ) ;
V_1 -> V_5 . V_8 = F_3 ( V_3 ) ;
}
int F_4 ( const T_5 * V_9 , const T_5 * V_10 )
{
T_6 V_11 , V_12 ;
T_7 V_13 , V_14 ;
V_11 = V_9 -> V_5 . V_7 ;
V_12 = V_10 -> V_5 . V_7 ;
if ( V_11 != V_12 )
return F_5 ( V_11 ) < F_5 ( V_12 ) ? - 1 : 1 ;
if ( V_9 -> V_5 . V_6 != V_10 -> V_5 . V_6 )
return V_9 -> V_5 . V_6 < V_10 -> V_5 . V_6 ? - 1 : 1 ;
V_13 = V_9 -> V_5 . V_8 ;
V_14 = V_10 -> V_5 . V_8 ;
if ( V_13 == V_14 )
return 0 ;
return F_6 ( V_13 ) < F_6 ( V_14 ) ? - 1 : 1 ;
}
static T_3 F_7 ( struct V_15 * V_5 , T_3 V_16 )
{
int V_17 ;
T_3 V_18 ;
for ( V_17 = 0 ; V_17 < 3 ; V_5 ++ , V_17 ++ ) {
V_18 = F_6 ( V_5 -> V_18 ) ;
if ( V_16 < V_18 )
return F_6 ( V_5 -> V_3 ) + V_16 ;
V_16 -= V_18 ;
}
return 0 ;
}
static int F_8 ( struct V_15 * V_5 )
{
int V_17 ;
T_3 V_18 = 0 ;
for ( V_17 = 0 ; V_17 < 3 ; V_5 ++ , V_17 ++ )
V_18 += F_6 ( V_5 -> V_18 ) ;
return V_18 ;
}
static T_3 F_9 ( struct V_15 * V_5 )
{
int V_17 ;
V_5 += 2 ;
for ( V_17 = 0 ; V_17 < 2 ; V_5 -- , V_17 ++ )
if ( V_5 -> V_18 )
break;
return F_6 ( V_5 -> V_3 ) + F_6 ( V_5 -> V_18 ) ;
}
static void F_10 ( struct V_19 * V_19 , struct V_20 * V_21 )
{
int V_22 ;
F_1 ( V_21 -> V_23 , V_19 -> V_24 , F_11 ( V_19 ) -> V_25 ,
F_12 ( V_19 ) ? V_26 : V_27 ) ;
V_22 = F_13 ( V_21 ) ;
if ( F_11 ( V_19 ) -> V_28 & V_29 ) {
if ( V_22 != - V_30 )
return;
F_14 ( V_21 , F_11 ( V_19 ) -> V_31 , sizeof( V_32 ) ) ;
F_11 ( V_19 ) -> V_28 &= ~ ( V_33 | V_29 ) ;
} else {
if ( V_22 )
return;
F_15 ( V_21 -> V_34 , F_11 ( V_19 ) -> V_31 , V_21 -> V_35 , V_21 -> V_36 ) ;
F_11 ( V_19 ) -> V_28 &= ~ V_33 ;
}
}
void F_16 ( struct V_19 * V_19 )
{
struct V_20 V_21 ;
if ( F_11 ( V_19 ) -> V_28 & V_33 ) {
F_17 ( F_18 ( V_19 -> V_37 ) -> V_38 , & V_21 ) ;
F_10 ( V_19 , & V_21 ) ;
F_19 ( & V_21 ) ;
}
}
static inline int F_20 ( struct V_20 * V_21 , struct V_15 * V_39 ,
T_2 V_2 , T_2 V_3 , T_4 type )
{
int V_22 ;
F_1 ( V_21 -> V_23 , V_2 , V_3 , type ) ;
V_21 -> V_1 -> V_5 . V_7 = 0 ;
V_22 = F_13 ( V_21 ) ;
if ( V_22 && V_22 != - V_30 )
return V_22 ;
if ( V_21 -> V_1 -> V_5 . V_7 != V_21 -> V_23 -> V_5 . V_7 ||
V_21 -> V_1 -> V_5 . V_6 != V_21 -> V_23 -> V_5 . V_6 )
return - V_30 ;
if ( V_21 -> V_36 != sizeof( V_32 ) )
return - V_40 ;
F_21 ( V_21 -> V_34 , V_39 , V_21 -> V_35 , sizeof( V_32 ) ) ;
return 0 ;
}
static inline int F_22 ( struct V_20 * V_21 , struct V_19 * V_19 , T_2 V_3 )
{
int V_22 ;
if ( F_11 ( V_19 ) -> V_28 & V_33 )
F_10 ( V_19 , V_21 ) ;
V_22 = F_20 ( V_21 , F_11 ( V_19 ) -> V_31 , V_19 -> V_24 ,
V_3 , F_12 ( V_19 ) ? V_26 : V_27 ) ;
if ( ! V_22 ) {
F_11 ( V_19 ) -> V_25 = F_6 ( V_21 -> V_1 -> V_5 . V_8 ) ;
F_11 ( V_19 ) -> V_41 = F_8 ( F_11 ( V_19 ) -> V_31 ) ;
} else {
F_11 ( V_19 ) -> V_25 = F_11 ( V_19 ) -> V_41 = 0 ;
F_11 ( V_19 ) -> V_28 &= ~ ( V_33 | V_29 ) ;
}
return V_22 ;
}
static int F_23 ( struct V_19 * V_19 , T_3 V_3 )
{
struct V_20 V_21 ;
int V_22 ;
if ( V_3 >= F_11 ( V_19 ) -> V_25 &&
V_3 < F_11 ( V_19 ) -> V_25 + F_11 ( V_19 ) -> V_41 )
return 0 ;
F_17 ( F_18 ( V_19 -> V_37 ) -> V_38 , & V_21 ) ;
V_22 = F_22 ( & V_21 , V_19 , V_3 ) ;
F_19 ( & V_21 ) ;
return V_22 ;
}
static void F_24 ( struct V_15 * V_39 )
{
int V_17 ;
F_25 ( V_42 , L_1 ) ;
for ( V_17 = 0 ; V_17 < 3 ; V_17 ++ )
F_25 ( V_42 , L_2 , F_6 ( V_39 [ V_17 ] . V_3 ) ,
F_6 ( V_39 [ V_17 ] . V_18 ) ) ;
F_25 ( V_42 , L_3 ) ;
}
static int F_26 ( struct V_15 * V_39 , T_3 V_43 ,
T_3 V_44 , T_3 V_45 )
{
T_3 V_18 , V_46 ;
int V_17 ;
F_24 ( V_39 ) ;
for ( V_17 = 0 ; V_17 < 3 ; V_39 ++ , V_17 ++ ) {
V_18 = F_6 ( V_39 -> V_18 ) ;
if ( V_43 == V_18 ) {
V_46 = F_6 ( V_39 -> V_3 ) ;
if ( V_44 != V_46 + V_18 ) {
if ( ++ V_17 >= 3 )
return - V_47 ;
V_39 ++ ;
V_39 -> V_3 = F_3 ( V_44 ) ;
} else
V_45 += V_18 ;
V_39 -> V_18 = F_3 ( V_45 ) ;
return 0 ;
} else if ( V_43 < V_18 )
break;
V_43 -= V_18 ;
}
return - V_40 ;
}
static int F_27 ( struct V_48 * V_49 , struct V_15 * V_39 ,
T_3 V_43 , T_3 V_50 )
{
T_3 V_18 , V_46 ;
int V_17 ;
F_24 ( V_39 ) ;
for ( V_17 = 0 ; V_17 < 3 ; V_39 ++ , V_17 ++ ) {
V_18 = F_6 ( V_39 -> V_18 ) ;
if ( V_43 == V_18 )
goto V_51;
else if ( V_43 < V_18 )
break;
V_43 -= V_18 ;
}
return - V_40 ;
V_51:
for (; ; ) {
V_46 = F_6 ( V_39 -> V_3 ) ;
if ( V_18 <= V_50 ) {
F_28 ( V_49 , V_46 , V_18 ) ;
V_39 -> V_3 = 0 ;
V_39 -> V_18 = 0 ;
V_50 -= V_18 ;
} else {
V_18 -= V_50 ;
F_28 ( V_49 , V_46 + V_18 , V_50 ) ;
V_39 -> V_18 = F_3 ( V_18 ) ;
V_50 = 0 ;
}
if ( ! V_50 || ! V_17 )
return 0 ;
V_17 -- ;
V_39 -- ;
V_18 = F_6 ( V_39 -> V_18 ) ;
}
}
int F_29 ( struct V_48 * V_49 , struct V_52 * V_53 , int type )
{
struct V_20 V_21 ;
T_2 V_54 , V_55 , V_46 ;
T_2 V_2 = F_5 ( V_53 -> V_56 ) ;
struct V_15 * V_39 ;
int V_22 , V_17 ;
if ( type == V_27 ) {
V_54 = F_5 ( V_53 -> V_57 ) ;
V_39 = V_53 -> V_58 ;
} else {
V_54 = F_5 ( V_53 -> V_59 ) ;
V_39 = V_53 -> V_60 ;
}
V_54 /= F_18 ( V_49 ) -> V_61 ;
if ( ! V_54 )
return 0 ;
V_55 = 0 ;
for ( V_17 = 0 ; V_17 < 3 ; V_39 ++ , V_17 ++ )
V_55 += F_6 ( V_39 [ V_17 ] . V_18 ) ;
V_22 = F_27 ( V_49 , V_39 , V_55 , V_55 ) ;
if ( V_22 )
return V_22 ;
if ( V_54 == V_55 )
return 0 ;
F_17 ( F_18 ( V_49 ) -> V_38 , & V_21 ) ;
do {
V_22 = F_20 ( & V_21 , V_39 , V_2 , V_54 , type ) ;
if ( V_22 )
break;
V_46 = F_6 ( V_21 . V_1 -> V_5 . V_8 ) ;
F_27 ( V_49 , V_39 , V_54 - V_46 , V_54 ) ;
F_30 ( & V_21 ) ;
V_54 = V_46 ;
} while ( V_54 > V_55 );
F_19 ( & V_21 ) ;
return V_22 ;
}
int F_31 ( struct V_19 * V_19 , T_8 V_3 ,
struct V_62 * V_63 , int V_64 )
{
struct V_48 * V_49 ;
T_3 V_65 , V_66 ;
int V_22 ;
V_49 = V_19 -> V_37 ;
V_66 = ( T_2 ) V_3 / F_18 ( V_49 ) -> V_67 ;
if ( V_3 >= F_11 ( V_19 ) -> V_68 ) {
if ( V_3 > F_11 ( V_19 ) -> V_68 || ! V_64 )
return - V_40 ;
if ( V_66 >= F_11 ( V_19 ) -> V_69 ) {
V_22 = F_32 ( V_19 ) ;
if ( V_22 )
return V_22 ;
}
} else
V_64 = 0 ;
if ( V_66 < F_11 ( V_19 ) -> V_70 ) {
V_65 = F_7 ( F_11 ( V_19 ) -> V_71 , V_66 ) ;
goto V_72;
}
F_33 ( & F_11 ( V_19 ) -> V_73 ) ;
V_22 = F_23 ( V_19 , V_66 ) ;
if ( ! V_22 )
V_65 = F_7 ( F_11 ( V_19 ) -> V_31 ,
V_66 - F_11 ( V_19 ) -> V_25 ) ;
else {
F_34 ( & F_11 ( V_19 ) -> V_73 ) ;
return - V_40 ;
}
F_34 ( & F_11 ( V_19 ) -> V_73 ) ;
V_72:
F_35 ( V_63 , V_49 , F_18 ( V_49 ) -> V_74 +
V_65 * F_18 ( V_49 ) -> V_67 +
( T_2 ) V_3 % F_18 ( V_49 ) -> V_67 ) ;
if ( V_64 ) {
F_36 ( V_63 ) ;
F_11 ( V_19 ) -> V_75 += V_49 -> V_76 ;
F_11 ( V_19 ) -> V_68 ++ ;
F_37 ( V_19 , V_49 -> V_76 ) ;
F_38 ( V_19 ) ;
}
return 0 ;
}
int F_32 ( struct V_19 * V_19 )
{
struct V_48 * V_49 = V_19 -> V_37 ;
T_2 V_46 , V_77 , V_78 ;
int V_22 ;
F_33 ( & F_11 ( V_19 ) -> V_73 ) ;
if ( F_11 ( V_19 ) -> V_69 == F_11 ( V_19 ) -> V_70 )
V_78 = F_9 ( F_11 ( V_19 ) -> V_71 ) ;
else {
V_22 = F_23 ( V_19 , F_11 ( V_19 ) -> V_69 ) ;
if ( V_22 )
goto V_79;
V_78 = F_9 ( F_11 ( V_19 ) -> V_31 ) ;
}
V_77 = F_11 ( V_19 ) -> V_80 ;
V_46 = F_39 ( V_49 , V_78 , & V_77 ) ;
if ( ! V_77 ) {
V_22 = - V_47 ;
goto V_79;
}
F_25 ( V_42 , L_4 , V_19 -> V_24 , V_46 , V_77 ) ;
if ( F_11 ( V_19 ) -> V_69 == F_11 ( V_19 ) -> V_70 ) {
if ( ! F_11 ( V_19 ) -> V_70 ) {
F_25 ( V_42 , L_5 ) ;
F_11 ( V_19 ) -> V_71 [ 0 ] . V_3 = F_3 ( V_46 ) ;
F_11 ( V_19 ) -> V_71 [ 0 ] . V_18 = F_3 ( V_77 ) ;
V_22 = 0 ;
} else {
V_22 = F_26 ( F_11 ( V_19 ) -> V_71 ,
F_11 ( V_19 ) -> V_69 ,
V_46 , V_77 ) ;
if ( V_22 == - V_47 )
goto V_81;
}
if ( ! V_22 ) {
F_24 ( F_11 ( V_19 ) -> V_71 ) ;
F_11 ( V_19 ) -> V_70 += V_77 ;
}
} else {
V_22 = F_26 ( F_11 ( V_19 ) -> V_31 ,
F_11 ( V_19 ) -> V_69 -
F_11 ( V_19 ) -> V_25 ,
V_46 , V_77 ) ;
if ( ! V_22 ) {
F_24 ( F_11 ( V_19 ) -> V_31 ) ;
F_11 ( V_19 ) -> V_28 |= V_33 ;
F_11 ( V_19 ) -> V_41 += V_77 ;
} else if ( V_22 == - V_47 )
goto V_81;
}
V_79:
F_34 ( & F_11 ( V_19 ) -> V_73 ) ;
if ( ! V_22 ) {
F_11 ( V_19 ) -> V_69 += V_77 ;
F_38 ( V_19 ) ;
if ( V_19 -> V_24 < V_82 )
F_40 ( V_83 , & F_18 ( V_49 ) -> V_28 ) ;
F_40 ( V_84 , & F_18 ( V_49 ) -> V_28 ) ;
F_41 ( V_49 ) ;
}
return V_22 ;
V_81:
F_25 ( V_42 , L_6 ) ;
F_16 ( V_19 ) ;
memset ( F_11 ( V_19 ) -> V_31 , 0 , sizeof( V_32 ) ) ;
F_11 ( V_19 ) -> V_31 [ 0 ] . V_3 = F_3 ( V_46 ) ;
F_11 ( V_19 ) -> V_31 [ 0 ] . V_18 = F_3 ( V_77 ) ;
F_24 ( F_11 ( V_19 ) -> V_31 ) ;
F_11 ( V_19 ) -> V_28 |= V_33 | V_29 ;
F_11 ( V_19 ) -> V_25 = F_11 ( V_19 ) -> V_69 ;
F_11 ( V_19 ) -> V_41 = V_77 ;
V_22 = 0 ;
goto V_79;
}
void F_42 ( struct V_19 * V_19 )
{
struct V_48 * V_49 = V_19 -> V_37 ;
struct V_20 V_21 ;
T_3 V_85 , V_86 , V_46 ;
T_2 V_87 ;
int V_22 ;
F_25 ( V_88 , L_7 , V_19 -> V_24 ,
( long long ) F_11 ( V_19 ) -> V_75 , V_19 -> V_89 ) ;
if ( V_19 -> V_89 > F_11 ( V_19 ) -> V_75 ) {
struct V_90 * V_91 = V_19 -> V_92 ;
void * V_93 ;
struct V_94 * V_94 ;
int V_22 ;
V_87 = V_19 -> V_89 - 1 ;
V_22 = F_43 ( NULL , V_91 , V_87 + 1 , 0 ,
V_95 , & V_94 , & V_93 ) ;
if ( ! V_22 ) {
V_22 = F_44 ( NULL , V_91 , V_87 + 1 , 0 , 0 ,
V_94 , V_93 ) ;
}
if ( V_22 )
V_19 -> V_89 = F_11 ( V_19 ) -> V_75 ;
return;
} else if ( V_19 -> V_89 == F_11 ( V_19 ) -> V_75 )
return;
V_87 = V_19 -> V_89 + F_18 ( V_49 ) -> V_61 - 1 ;
V_85 = V_87 / F_18 ( V_49 ) -> V_61 ;
V_86 = F_11 ( V_19 ) -> V_69 ;
if ( V_85 == V_86 )
goto V_79;
F_33 ( & F_11 ( V_19 ) -> V_73 ) ;
F_17 ( F_18 ( V_49 ) -> V_38 , & V_21 ) ;
while ( 1 ) {
if ( V_86 == F_11 ( V_19 ) -> V_70 ) {
F_27 ( V_49 , F_11 ( V_19 ) -> V_71 ,
V_86 , V_86 - V_85 ) ;
F_24 ( F_11 ( V_19 ) -> V_71 ) ;
F_11 ( V_19 ) -> V_70 = V_85 ;
break;
}
V_22 = F_22 ( & V_21 , V_19 , V_86 ) ;
if ( V_22 )
break;
V_46 = F_11 ( V_19 ) -> V_25 ;
F_27 ( V_49 , F_11 ( V_19 ) -> V_31 ,
V_86 - V_46 , V_86 - V_85 ) ;
F_24 ( F_11 ( V_19 ) -> V_31 ) ;
if ( V_85 > V_46 ) {
F_11 ( V_19 ) -> V_28 |= V_33 ;
break;
}
V_86 = V_46 ;
F_11 ( V_19 ) -> V_25 = F_11 ( V_19 ) -> V_41 = 0 ;
F_11 ( V_19 ) -> V_28 &= ~ ( V_33 | V_29 ) ;
F_30 ( & V_21 ) ;
}
F_19 ( & V_21 ) ;
F_34 ( & F_11 ( V_19 ) -> V_73 ) ;
F_11 ( V_19 ) -> V_69 = V_85 ;
V_79:
F_11 ( V_19 ) -> V_75 = V_19 -> V_89 ;
F_11 ( V_19 ) -> V_68 = ( V_19 -> V_89 + V_49 -> V_76 - 1 ) >> V_49 -> V_96 ;
F_45 ( V_19 , F_11 ( V_19 ) -> V_68 << V_49 -> V_96 ) ;
F_38 ( V_19 ) ;
}
