static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
unsigned int V_9 = F_4 ( V_4 ) ;
struct V_10 * V_11 = F_5 ( V_2 ) ;
T_1 V_12 = V_11 -> V_12 ;
T_1 V_13 = V_14 ;
T_1 V_15 = 0 ;
T_1 V_16 ;
T_1 V_17 ;
int V_18 , V_19 = 0 ;
unsigned int V_20 = V_2 -> V_21 ;
unsigned int V_22 = V_2 -> V_21 ;
unsigned int V_23 ;
struct V_24 V_25 , V_26 ;
unsigned int V_27 , V_28 ;
if ( V_2 -> V_21 == 0 )
return 0 ;
if ( ! V_2 -> V_29 ) {
F_6 ( V_8 -> V_30 , L_1 ) ;
return - V_31 ;
}
if ( ! V_2 -> V_32 || ! V_2 -> V_33 ) {
F_6 ( V_8 -> V_30 , L_2 ) ;
return - V_31 ;
}
F_7 ( & V_8 -> V_34 ) ;
for ( V_18 = 0 ; V_18 < V_6 -> V_35 ; V_18 += 4 )
F_8 ( * ( V_6 -> V_36 + V_18 / 4 ) , V_8 -> V_37 + V_38 + V_18 ) ;
if ( V_2 -> V_29 ) {
for ( V_18 = 0 ; V_18 < 4 && V_18 < V_9 / 4 ; V_18 ++ ) {
V_17 = * ( T_1 * ) ( V_2 -> V_29 + V_18 * 4 ) ;
F_8 ( V_17 , V_8 -> V_37 + V_39 + V_18 * 4 ) ;
}
}
F_8 ( V_12 , V_8 -> V_37 + V_40 ) ;
F_9 ( & V_25 , V_2 -> V_32 , F_10 ( V_2 -> V_32 ) ,
V_41 | V_42 ) ;
F_9 ( & V_26 , V_2 -> V_33 , F_10 ( V_2 -> V_33 ) ,
V_43 | V_42 ) ;
F_11 ( & V_25 ) ;
F_11 ( & V_26 ) ;
if ( ! V_25 . V_44 || ! V_26 . V_44 ) {
F_6 ( V_8 -> V_30 , L_3 ) ;
V_19 = - V_31 ;
goto V_45;
}
V_20 = V_2 -> V_21 / 4 ;
V_22 = V_2 -> V_21 / 4 ;
V_27 = 0 ;
V_28 = 0 ;
do {
V_23 = F_12 ( V_13 , V_20 , ( V_25 . V_46 - V_27 ) / 4 ) ;
if ( V_23 > 0 ) {
V_20 -= V_23 ;
F_13 ( V_8 -> V_37 + V_47 , V_25 . V_44 + V_27 , V_23 ) ;
V_27 += V_23 * 4 ;
}
if ( V_27 == V_25 . V_46 ) {
F_11 ( & V_25 ) ;
V_27 = 0 ;
}
V_16 = F_14 ( V_8 -> V_37 + V_48 ) ;
V_13 = F_15 ( V_16 ) ;
V_15 = F_16 ( V_16 ) ;
V_23 = F_12 ( V_15 , V_22 , ( V_26 . V_46 - V_28 ) / 4 ) ;
if ( V_23 > 0 ) {
V_22 -= V_23 ;
F_17 ( V_8 -> V_37 + V_49 , V_26 . V_44 + V_28 , V_23 ) ;
V_28 += V_23 * 4 ;
}
if ( V_28 == V_26 . V_46 ) {
F_11 ( & V_26 ) ;
V_28 = 0 ;
}
} while ( V_22 > 0 );
if ( V_2 -> V_29 ) {
for ( V_18 = 0 ; V_18 < 4 && V_18 < V_9 / 4 ; V_18 ++ ) {
V_17 = F_14 ( V_8 -> V_37 + V_39 + V_18 * 4 ) ;
* ( T_1 * ) ( V_2 -> V_29 + V_18 * 4 ) = V_17 ;
}
}
V_45:
F_18 ( & V_25 ) ;
F_18 ( & V_26 ) ;
F_8 ( 0 , V_8 -> V_37 + V_40 ) ;
F_19 ( & V_8 -> V_34 ) ;
return V_19 ;
}
static int F_20 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
int V_50 = 1 ;
struct V_51 * V_52 = V_2 -> V_32 ;
struct V_51 * V_53 = V_2 -> V_33 ;
unsigned int V_9 = F_4 ( V_4 ) ;
struct V_10 * V_11 = F_5 ( V_2 ) ;
T_1 V_12 = V_11 -> V_12 ;
T_1 V_13 = V_14 ;
T_1 V_15 = 0 ;
T_1 V_17 ;
T_1 V_16 ;
int V_18 , V_19 = 0 ;
unsigned int V_20 = V_2 -> V_21 ;
unsigned int V_22 = V_2 -> V_21 ;
unsigned int V_23 ;
struct V_24 V_25 , V_26 ;
unsigned int V_27 , V_28 ;
char V_54 [ 4 * V_55 ] ;
char V_56 [ 4 * V_57 ] ;
unsigned int V_58 = 0 ;
unsigned int V_59 = 0 ;
unsigned int V_60 = 0 ;
if ( V_2 -> V_21 == 0 )
return 0 ;
if ( ! V_2 -> V_29 ) {
F_6 ( V_8 -> V_30 , L_1 ) ;
return - V_31 ;
}
if ( ! V_2 -> V_32 || ! V_2 -> V_33 ) {
F_6 ( V_8 -> V_30 , L_2 ) ;
return - V_31 ;
}
while ( V_52 && V_50 == 1 ) {
if ( ( V_52 -> V_46 % 4 ) != 0 )
V_50 = 0 ;
V_52 = F_21 ( V_52 ) ;
}
while ( V_53 && V_50 == 1 ) {
if ( ( V_53 -> V_46 % 4 ) != 0 )
V_50 = 0 ;
V_53 = F_21 ( V_53 ) ;
}
if ( V_50 == 1 )
return F_1 ( V_2 ) ;
F_7 ( & V_8 -> V_34 ) ;
for ( V_18 = 0 ; V_18 < V_6 -> V_35 ; V_18 += 4 )
F_8 ( * ( V_6 -> V_36 + V_18 / 4 ) , V_8 -> V_37 + V_38 + V_18 ) ;
if ( V_2 -> V_29 ) {
for ( V_18 = 0 ; V_18 < 4 && V_18 < V_9 / 4 ; V_18 ++ ) {
V_17 = * ( T_1 * ) ( V_2 -> V_29 + V_18 * 4 ) ;
F_8 ( V_17 , V_8 -> V_37 + V_39 + V_18 * 4 ) ;
}
}
F_8 ( V_12 , V_8 -> V_37 + V_40 ) ;
F_9 ( & V_25 , V_2 -> V_32 , F_10 ( V_2 -> V_32 ) ,
V_41 | V_42 ) ;
F_9 ( & V_26 , V_2 -> V_33 , F_10 ( V_2 -> V_33 ) ,
V_43 | V_42 ) ;
F_11 ( & V_25 ) ;
F_11 ( & V_26 ) ;
if ( ! V_25 . V_44 || ! V_26 . V_44 ) {
F_6 ( V_8 -> V_30 , L_3 ) ;
V_19 = - V_31 ;
goto V_45;
}
V_20 = V_2 -> V_21 ;
V_22 = V_2 -> V_21 ;
V_27 = 0 ;
V_28 = 0 ;
while ( V_22 > 0 ) {
if ( V_20 > 0 ) {
V_23 = F_12 ( V_13 , V_20 / 4 , ( V_25 . V_46 - V_27 ) / 4 ) ;
if ( V_23 > 0 && V_58 == 0 ) {
F_13 ( V_8 -> V_37 + V_47 , V_25 . V_44 + V_27 ,
V_23 ) ;
V_20 -= V_23 * 4 ;
V_27 += V_23 * 4 ;
} else {
V_23 = F_12 ( V_13 * 4 - V_58 , V_20 ,
V_25 . V_46 - V_27 ) ;
memcpy ( V_54 + V_58 , V_25 . V_44 + V_27 , V_23 ) ;
V_20 -= V_23 ;
V_27 += V_23 ;
V_58 += V_23 ;
if ( V_58 % 4 == 0 ) {
F_13 ( V_8 -> V_37 + V_47 , V_54 ,
V_58 / 4 ) ;
V_58 = 0 ;
}
}
if ( V_27 == V_25 . V_46 ) {
F_11 ( & V_25 ) ;
V_27 = 0 ;
}
}
V_16 = F_14 ( V_8 -> V_37 + V_48 ) ;
V_13 = F_15 ( V_16 ) ;
V_15 = F_16 ( V_16 ) ;
F_22 ( V_8 -> V_30 , L_4 ,
V_12 ,
V_27 , V_25 . V_46 , V_20 , V_2 -> V_21 , V_13 ,
V_28 , V_26 . V_46 , V_22 , V_2 -> V_21 , V_15 ,
V_23 , V_58 ) ;
if ( V_15 == 0 )
continue;
V_23 = F_12 ( V_15 , V_22 / 4 , ( V_26 . V_46 - V_28 ) / 4 ) ;
if ( V_23 > 0 ) {
F_17 ( V_8 -> V_37 + V_49 , V_26 . V_44 + V_28 , V_23 ) ;
V_22 -= V_23 * 4 ;
V_28 += V_23 * 4 ;
if ( V_28 == V_26 . V_46 ) {
F_11 ( & V_26 ) ;
V_28 = 0 ;
}
} else {
F_17 ( V_8 -> V_37 + V_49 , V_56 , V_15 ) ;
V_60 = V_15 * 4 ;
V_59 = 0 ;
do {
V_23 = F_23 ( V_26 . V_46 - V_28 , V_60 - V_59 ) ;
memcpy ( V_26 . V_44 + V_28 , V_56 + V_59 , V_23 ) ;
V_22 -= V_23 ;
V_59 += V_23 ;
V_28 += V_23 ;
if ( V_28 == V_26 . V_46 ) {
F_11 ( & V_26 ) ;
V_28 = 0 ;
}
} while ( V_59 < V_60 );
}
}
if ( V_2 -> V_29 ) {
for ( V_18 = 0 ; V_18 < 4 && V_18 < V_9 / 4 ; V_18 ++ ) {
V_17 = F_14 ( V_8 -> V_37 + V_39 + V_18 * 4 ) ;
* ( T_1 * ) ( V_2 -> V_29 + V_18 * 4 ) = V_17 ;
}
}
V_45:
F_18 ( & V_25 ) ;
F_18 ( & V_26 ) ;
F_8 ( 0 , V_8 -> V_37 + V_40 ) ;
F_19 ( & V_8 -> V_34 ) ;
return V_19 ;
}
int F_24 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
struct V_10 * V_61 = F_5 ( V_2 ) ;
V_61 -> V_12 = V_62 | V_63 | V_64 | V_65 |
V_6 -> V_66 ;
return F_20 ( V_2 ) ;
}
int F_25 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
struct V_10 * V_61 = F_5 ( V_2 ) ;
V_61 -> V_12 = V_62 | V_63 | V_64 | V_67 |
V_6 -> V_66 ;
return F_20 ( V_2 ) ;
}
int F_26 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
struct V_10 * V_61 = F_5 ( V_2 ) ;
V_61 -> V_12 = V_62 | V_68 | V_64 | V_65 |
V_6 -> V_66 ;
return F_20 ( V_2 ) ;
}
int F_27 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
struct V_10 * V_61 = F_5 ( V_2 ) ;
V_61 -> V_12 = V_62 | V_68 | V_64 | V_67 |
V_6 -> V_66 ;
return F_20 ( V_2 ) ;
}
int F_28 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
struct V_10 * V_61 = F_5 ( V_2 ) ;
V_61 -> V_12 = V_69 | V_63 | V_64 | V_65 |
V_6 -> V_66 ;
return F_20 ( V_2 ) ;
}
int F_29 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
struct V_10 * V_61 = F_5 ( V_2 ) ;
V_61 -> V_12 = V_69 | V_63 | V_64 | V_67 |
V_6 -> V_66 ;
return F_20 ( V_2 ) ;
}
int F_30 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
struct V_10 * V_61 = F_5 ( V_2 ) ;
V_61 -> V_12 = V_69 | V_68 | V_64 | V_65 |
V_6 -> V_66 ;
return F_20 ( V_2 ) ;
}
int F_31 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
struct V_10 * V_61 = F_5 ( V_2 ) ;
V_61 -> V_12 = V_69 | V_68 | V_64 | V_67 |
V_6 -> V_66 ;
return F_20 ( V_2 ) ;
}
int F_32 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
struct V_10 * V_61 = F_5 ( V_2 ) ;
V_61 -> V_12 = V_70 | V_63 | V_64 | V_65 |
V_6 -> V_66 ;
return F_20 ( V_2 ) ;
}
int F_33 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
struct V_10 * V_61 = F_5 ( V_2 ) ;
V_61 -> V_12 = V_70 | V_63 | V_64 | V_67 |
V_6 -> V_66 ;
return F_20 ( V_2 ) ;
}
int F_34 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
struct V_10 * V_61 = F_5 ( V_2 ) ;
V_61 -> V_12 = V_70 | V_68 | V_64 | V_65 |
V_6 -> V_66 ;
return F_20 ( V_2 ) ;
}
int F_35 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
struct V_10 * V_61 = F_5 ( V_2 ) ;
V_61 -> V_12 = V_70 | V_68 | V_64 | V_67 |
V_6 -> V_66 ;
return F_20 ( V_2 ) ;
}
int F_36 ( struct V_71 * V_4 )
{
struct V_5 * V_6 = F_37 ( V_4 ) ;
struct V_72 * V_73 = V_4 -> V_74 ;
struct V_75 * V_76 ;
memset ( V_6 , 0 , sizeof( struct V_5 ) ) ;
V_76 = F_38 ( V_73 , struct V_75 , V_73 . V_77 ) ;
V_6 -> V_8 = V_76 -> V_8 ;
V_4 -> V_78 . V_79 = sizeof( struct V_10 ) ;
return 0 ;
}
int F_39 ( struct V_3 * V_4 , const T_2 * V_36 ,
unsigned int V_35 )
{
struct V_5 * V_6 = F_3 ( V_4 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
switch ( V_35 ) {
case 128 / 8 :
V_6 -> V_66 = V_80 ;
break;
case 192 / 8 :
V_6 -> V_66 = V_81 ;
break;
case 256 / 8 :
V_6 -> V_66 = V_82 ;
break;
default:
F_40 ( V_8 -> V_30 , L_5 , V_35 ) ;
F_41 ( V_4 , V_83 ) ;
return - V_31 ;
}
V_6 -> V_35 = V_35 ;
memcpy ( V_6 -> V_36 , V_36 , V_35 ) ;
return 0 ;
}
int F_42 ( struct V_3 * V_4 , const T_2 * V_36 ,
unsigned int V_35 )
{
struct V_5 * V_6 = F_3 ( V_4 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
T_1 V_84 ;
T_1 V_85 [ V_86 ] ;
int V_87 ;
if ( F_43 ( V_35 != V_88 ) ) {
F_40 ( V_8 -> V_30 , L_6 , V_35 ) ;
F_41 ( V_4 , V_83 ) ;
return - V_31 ;
}
V_84 = F_44 ( V_4 ) ;
V_87 = F_45 ( V_85 , V_36 ) ;
if ( F_43 ( V_87 == 0 ) && ( V_84 & V_89 ) ) {
F_41 ( V_4 , V_90 ) ;
F_22 ( V_8 -> V_30 , L_7 , V_35 ) ;
return - V_31 ;
}
V_6 -> V_35 = V_35 ;
memcpy ( V_6 -> V_36 , V_36 , V_35 ) ;
return 0 ;
}
int F_46 ( struct V_3 * V_4 , const T_2 * V_36 ,
unsigned int V_35 )
{
struct V_5 * V_6 = F_3 ( V_4 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
if ( F_43 ( V_35 != 3 * V_88 ) ) {
F_40 ( V_8 -> V_30 , L_6 , V_35 ) ;
F_41 ( V_4 , V_83 ) ;
return - V_31 ;
}
V_6 -> V_35 = V_35 ;
memcpy ( V_6 -> V_36 , V_36 , V_35 ) ;
return 0 ;
}
