static int F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_4 * V_5 ;
struct V_6 * V_7 ;
void * V_8 ;
T_1 V_9 , V_10 , V_11 , V_12 , V_13 , V_14 ;
unsigned V_15 , V_16 ;
unsigned V_17 , V_18 ;
int V_19 ;
F_3 ( L_1 , V_1 -> V_20 ) ;
V_5 = V_1 -> V_21 ;
V_7 = F_4 ( V_5 ) -> V_22 ;
V_15 = 0 ;
V_16 = 0 ;
V_19 = 0 ;
V_9 = V_23 ;
V_12 = F_5 ( T_1 , V_24 , V_3 -> V_25 ) ;
V_10 = ( ( V_9 & V_7 -> V_26 ) ? ( ( V_9 | V_7 -> V_26 ) + 1 ) : V_9 ) ;
V_11 = V_12 & ~ V_7 -> V_26 ;
V_13 = V_14 = 0 ;
if ( V_10 > V_11 ) {
V_10 = V_12 ;
V_11 = V_12 = 0 ;
} else if ( V_10 < V_11 ) {
V_13 = F_6 ( V_10 ) ;
V_14 = F_6 ( V_11 ) ;
}
F_3 ( L_2
L_3 , V_1 -> V_20 ,
( unsigned long long ) V_9 , ( unsigned long long ) V_10 ,
( unsigned long long ) V_13 , ( unsigned long long ) V_14 ,
( unsigned long long ) V_11 , ( unsigned long long ) V_12 ) ;
if ( V_9 >= V_10 )
goto V_27;
V_8 = F_7 ( V_7 , V_3 , F_6 ( V_9 ) ) ;
V_18 = F_8 ( V_5 , V_8 ) ;
if ( ! V_18 )
F_9 ( V_5 , L_4 , L_5 ) ;
V_10 -= V_9 ;
V_9 = F_10 ( V_9 ) ;
F_11 ( V_1 , V_18 + V_9 , V_10 ) ;
F_12 ( V_1 ) ;
V_15 = V_18 + V_9 ;
V_27:
for ( V_17 = V_13 ; V_17 < V_14 ; V_17 ++ ) {
V_8 = F_7 ( V_7 , V_3 , V_17 ) ;
V_18 = F_8 ( V_5 , V_8 ) ;
if ( ! V_18 )
continue;
F_13 ( V_7 , V_8 ) ;
if ( V_16 == 0 ) {
V_15 = V_18 ;
V_16 = V_7 -> V_28 ;
} else if ( V_16 > 0 && V_15 == V_18 - V_16 )
V_16 += V_7 -> V_28 ;
else {
F_14 ( V_1 , V_15 , V_16 ) ;
V_15 = V_18 ;
V_16 = V_7 -> V_28 ;
}
F_12 ( V_1 ) ;
}
if ( V_16 > 0 )
F_14 ( V_1 , V_15 , V_16 ) ;
if ( V_11 >= V_12 )
goto V_29;
V_8 = F_7 ( V_7 , V_3 , F_6 ( V_11 ) ) ;
V_18 = F_8 ( V_5 , V_8 ) ;
if ( ! V_18 )
F_9 ( V_5 , L_6 , L_5 ) ;
V_12 = F_10 ( V_12 ) ;
F_13 ( V_7 , V_8 ) ;
F_11 ( V_1 , V_18 , V_12 ) ;
F_12 ( V_1 ) ;
V_29:
F_3 ( L_7 , V_1 -> V_20 ) ;
return V_19 ;
}
static int F_15 ( struct V_1 * V_1 , T_1 V_30 , void * V_8 )
{
struct V_4 * V_5 ;
struct V_6 * V_7 ;
struct V_31 * V_32 ;
void * V_33 ;
T_1 V_18 , V_34 , V_17 , V_15 ;
unsigned V_16 ;
int V_19 ;
F_3 ( L_8 ,
V_1 -> V_20 , ( unsigned long long ) V_30 , V_8 ) ;
F_16 ( ! V_8 ) ;
V_5 = V_1 -> V_21 ;
V_7 = F_4 ( V_5 ) -> V_22 ;
V_15 = 0 ;
V_16 = 0 ;
V_19 = 0 ;
V_18 = F_8 ( V_5 , V_8 ) ;
if ( ! V_18 )
return 0 ;
V_32 = F_17 ( V_5 , V_18 , V_7 -> V_35 ) ;
if ( V_18 != F_8 ( V_5 , V_8 ) ) {
F_18 ( V_32 ) ;
return 1 ;
}
if ( ! V_32 ) {
F_13 ( V_7 , V_8 ) ;
return 0 ;
}
V_34 = ( V_36 > V_30 ) ? ( V_36 - V_30 ) : 0 ;
for ( V_17 = V_34 ; V_17 < V_7 -> V_37 ; V_17 ++ ) {
V_33 = F_19 ( V_7 , V_32 , V_17 ) ;
V_18 = F_8 ( V_5 , V_33 ) ;
if ( ! V_18 )
continue;
F_13 ( V_7 , V_33 ) ;
F_20 ( V_32 ) ;
if ( V_16 == 0 ) {
V_15 = V_18 ;
V_16 = V_7 -> V_28 ;
} else if ( V_16 > 0 && V_15 == V_18 - V_16 )
V_16 += V_7 -> V_28 ;
else {
F_14 ( V_1 , V_15 , V_16 ) ;
V_15 = V_18 ;
V_16 = V_7 -> V_28 ;
}
F_12 ( V_1 ) ;
}
if ( V_16 > 0 ) {
F_14 ( V_1 , V_15 , V_16 ) ;
}
for ( V_17 = 0 ; V_17 < V_7 -> V_37 ; V_17 ++ )
if ( ! F_21 ( V_7 ,
F_19 ( V_7 , V_32 , V_17 ) ) )
break;
if ( V_17 >= V_7 -> V_37 ) {
V_18 = F_8 ( V_5 , V_8 ) ;
F_13 ( V_7 , V_8 ) ;
F_14 ( V_1 , V_18 , V_7 -> V_28 ) ;
F_12 ( V_1 ) ;
F_22 ( V_32 ) ;
V_32 = NULL ;
}
if ( F_23 ( V_1 ) && V_32 && F_24 ( V_32 ) )
F_25 ( V_32 ) ;
F_18 ( V_32 ) ;
F_3 ( L_7 , V_1 -> V_20 ) ;
return V_19 ;
}
static int F_26 ( struct V_1 * V_1 , T_1 V_30 , void * V_8 )
{
struct V_4 * V_5 ;
struct V_6 * V_7 ;
struct V_31 * V_38 ;
T_1 V_17 , V_18 , V_39 ;
void * V_40 ;
int V_19 = 0 ;
F_3 ( L_1 , V_1 -> V_20 ) ;
V_5 = V_1 -> V_21 ;
V_7 = F_4 ( V_5 ) -> V_22 ;
V_39 = ( V_36 > V_30 )
? ( ( V_36 - V_30 ) >> V_7 -> V_41 ) : 0 ;
V_19 = 0 ;
V_18 = F_8 ( V_5 , V_8 ) ;
if ( ! V_18 )
return 0 ;
V_38 = F_17 ( V_5 , V_18 , V_7 -> V_35 ) ;
if ( V_18 != F_8 ( V_5 , V_8 ) ) {
F_18 ( V_38 ) ;
return 1 ;
}
if ( ! V_38 ) {
F_13 ( V_7 , V_8 ) ;
return 0 ;
}
for ( V_17 = V_39 ; V_17 < V_7 -> V_37 ; V_17 ++ ) {
V_40 = F_19 ( V_7 , V_38 , V_17 ) ;
V_18 = F_8 ( V_5 , V_40 ) ;
if ( ! V_18 )
continue;
V_19 |= F_15 ( V_1 , V_30 + ( V_17 << V_7 -> V_41 ) , V_40 ) ;
F_20 ( V_38 ) ;
}
for ( V_17 = 0 ; V_17 < V_7 -> V_37 ; V_17 ++ )
if ( ! F_21 ( V_7 ,
F_19 ( V_7 , V_38 , V_17 ) ) )
break;
if ( V_17 >= V_7 -> V_37 ) {
V_18 = F_8 ( V_5 , V_8 ) ;
F_13 ( V_7 , V_8 ) ;
F_14 ( V_1 , V_18 , V_7 -> V_28 ) ;
F_12 ( V_1 ) ;
F_22 ( V_38 ) ;
V_38 = NULL ;
}
if ( F_23 ( V_1 ) && V_38 && F_24 ( V_38 ) )
F_25 ( V_38 ) ;
F_18 ( V_38 ) ;
F_3 ( L_7 , V_1 -> V_20 ) ;
return V_19 ;
}
static int F_27 ( struct V_1 * V_1 )
{
struct V_4 * V_5 = V_1 -> V_21 ;
struct V_6 * V_7 = F_4 ( V_5 ) -> V_22 ;
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_31 * V_42 ;
T_1 V_43 , V_18 , V_17 ;
void * V_44 , * V_8 ;
int V_19 ;
F_3 ( L_1 , V_1 -> V_20 ) ;
V_19 = 0 ;
V_43 = ( V_36 > ( V_45 + V_7 -> V_37 + V_7 -> V_46 ) )
? ( ( V_36 - V_45 - V_7 -> V_37 - V_7 -> V_46 ) >> V_7 -> V_47 ) : 0 ;
V_8 = F_7 ( V_7 , V_3 , V_48 ) ;
if ( ! ( V_18 = F_8 ( V_5 , V_8 ) ) )
return 0 ;
V_42 = F_17 ( V_5 , V_18 , V_7 -> V_35 ) ;
if ( V_18 != F_8 ( V_5 , V_8 ) ) {
F_18 ( V_42 ) ;
return 1 ;
}
if ( ! V_42 ) {
F_13 ( V_7 , V_8 ) ;
return 0 ;
}
for ( V_17 = V_43 ; V_17 < V_7 -> V_37 ; V_17 ++ ) {
V_44 = F_19 ( V_7 , V_42 , V_17 ) ;
V_19 |= F_26 ( V_1 , V_45 +
V_7 -> V_37 + ( ( V_17 + 1 ) << V_7 -> V_47 ) , V_44 ) ;
F_20 ( V_42 ) ;
}
for ( V_17 = 0 ; V_17 < V_7 -> V_37 ; V_17 ++ )
if ( ! F_21 ( V_7 ,
F_19 ( V_7 , V_42 , V_17 ) ) )
break;
if ( V_17 >= V_7 -> V_37 ) {
V_18 = F_8 ( V_5 , V_8 ) ;
F_13 ( V_7 , V_8 ) ;
F_14 ( V_1 , V_18 , V_7 -> V_28 ) ;
F_12 ( V_1 ) ;
F_22 ( V_42 ) ;
V_42 = NULL ;
}
if ( F_23 ( V_1 ) && V_42 && F_24 ( V_42 ) )
F_25 ( V_42 ) ;
F_18 ( V_42 ) ;
F_3 ( L_7 , V_1 -> V_20 ) ;
return V_19 ;
}
static int F_28 ( struct V_1 * V_1 )
{
int V_49 = 0 ;
struct V_4 * V_5 = V_1 -> V_21 ;
struct V_50 * V_51 = V_1 -> V_52 ;
struct V_6 * V_7 = F_4 ( V_5 ) -> V_22 ;
unsigned V_17 , V_53 ;
T_2 V_54 ;
struct V_55 * V_56 ;
struct V_57 * V_58 ;
T_1 V_59 ;
V_54 = ( F_29 ( V_1 ) + V_7 -> V_60 - 1 ) >> V_7 -> V_61 ;
if ( ! V_54 )
goto V_62;
V_54 -- ;
V_56 = F_30 ( V_51 , V_54 >>
( V_63 - V_1 -> V_64 ) ) ;
if ( F_31 ( V_56 ) ) {
V_49 = - V_65 ;
goto V_62;
}
V_53 = V_54 & ( ( 1 << ( V_63 - V_1 -> V_64 ) ) - 1 ) ;
V_58 = F_32 ( V_56 ) ;
for ( V_17 = 0 ; V_17 < V_53 ; ++ V_17 )
V_58 = V_58 -> V_66 ;
V_49 = F_33 ( V_1 , V_54 , V_58 , 1 ) ;
if ( F_34 ( V_49 ) )
goto V_67;
if ( F_35 ( V_58 ) ) {
F_36 ( V_58 ) ;
F_37 ( V_58 -> V_68 ,
V_58 -> V_69 ) ;
F_38 ( V_58 ) ;
F_39 ( V_58 ) ;
F_40 ( V_56 ) ;
}
if ( V_54 >= V_70 ) {
V_53 = V_7 -> V_28 - F_10 ( V_54 ) - 1 ;
V_59 = V_58 -> V_69 + 1 ;
for ( V_17 = 0 ; V_17 < V_53 ; ++ V_17 ) {
V_58 = F_41 ( V_5 , V_17 + V_59 ) ;
F_42 ( V_58 ) ;
memset ( V_58 -> V_71 , 0 , V_5 -> V_72 ) ;
F_38 ( V_58 ) ;
F_39 ( V_58 ) ;
F_43 ( V_58 ) ;
F_44 ( V_58 ) ;
F_45 ( V_58 ) ;
}
}
V_67:
F_46 ( V_56 ) ;
V_62:
return V_49 ;
}
int F_47 ( struct V_1 * V_1 , T_3 V_73 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_4 * V_5 = V_1 -> V_21 ;
struct V_6 * V_7 = F_4 ( V_5 ) -> V_22 ;
int V_19 , V_49 = 0 ;
F_3 ( L_9 ,
V_1 -> V_20 , ( unsigned long long ) F_29 ( V_1 ) ,
( unsigned long long ) V_73 ) ;
if ( ! ( F_48 ( V_1 -> V_74 ) || F_49 ( V_1 -> V_74 ) ||
F_50 ( V_1 -> V_74 ) ) )
return - V_75 ;
if ( F_51 ( V_1 ) || F_52 ( V_1 ) )
return - V_76 ;
V_49 = F_28 ( V_1 ) ;
if ( V_49 ) {
F_53 ( V_1 , V_73 ) ;
goto V_62;
}
F_54 ( V_1 -> V_52 , V_1 -> V_77 , F_33 ) ;
while ( 1 ) {
V_19 = F_1 ( V_1 ) ;
V_19 |= F_15 ( V_1 , V_78 ,
F_7 ( V_7 , V_3 ,
V_78 ) ) ;
V_19 |= F_26 ( V_1 , V_78 + V_7 -> V_37 ,
F_7 ( V_7 , V_3 ,
V_79 ) ) ;
V_19 |= F_27 ( V_1 ) ;
if ( ! V_19 )
break;
if ( F_23 ( V_1 ) && ( V_1 -> V_80 & V_81 ) )
F_55 ( V_1 ) ;
F_56 () ;
}
V_1 -> V_82 = V_1 -> V_83 = V_84 ;
V_3 -> V_25 = V_23 ;
F_12 ( V_1 ) ;
V_62:
F_3 ( L_10 , V_49 ) ;
return V_49 ;
}
int F_57 ( struct V_85 * V_85 , struct V_86 * V_87 )
{
struct V_1 * V_1 = V_85 -> V_88 ;
unsigned int V_89 = V_87 -> V_89 ;
int error ;
error = F_58 ( V_1 , V_87 ) ;
if ( error )
return error ;
if ( V_89 & V_90 && V_87 -> V_91 != V_1 -> V_77 ) {
T_3 V_73 = V_1 -> V_77 ;
F_59 ( V_1 , V_87 -> V_91 ) ;
F_60 ( V_1 -> V_21 ) ;
error = F_47 ( V_1 , V_73 ) ;
F_61 ( V_1 -> V_21 ) ;
if ( error )
return error ;
}
F_62 ( V_1 , V_87 ) ;
F_12 ( V_1 ) ;
return 0 ;
}
