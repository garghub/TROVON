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
int V_18 = 0 ;
unsigned int V_19 ;
unsigned int V_20 = V_2 -> V_21 ;
unsigned int V_22 = V_2 -> V_21 ;
unsigned int V_23 ;
struct V_24 V_25 , V_26 ;
unsigned int V_27 , V_28 ;
unsigned long V_29 ;
if ( V_2 -> V_21 == 0 )
return 0 ;
if ( ! V_2 -> V_30 ) {
F_6 ( V_8 -> V_31 , L_1 ) ;
return - V_32 ;
}
if ( ! V_2 -> V_33 || ! V_2 -> V_34 ) {
F_6 ( V_8 -> V_31 , L_2 ) ;
return - V_32 ;
}
F_7 ( & V_8 -> V_35 , V_29 ) ;
for ( V_19 = 0 ; V_19 < V_6 -> V_36 ; V_19 += 4 )
F_8 ( * ( V_6 -> V_37 + V_19 / 4 ) , V_8 -> V_38 + V_39 + V_19 ) ;
if ( V_2 -> V_30 ) {
for ( V_19 = 0 ; V_19 < 4 && V_19 < V_9 / 4 ; V_19 ++ ) {
V_17 = * ( T_1 * ) ( V_2 -> V_30 + V_19 * 4 ) ;
F_8 ( V_17 , V_8 -> V_38 + V_40 + V_19 * 4 ) ;
}
}
F_8 ( V_12 , V_8 -> V_38 + V_41 ) ;
F_9 ( & V_25 , V_2 -> V_33 , F_10 ( V_2 -> V_33 ) ,
V_42 | V_43 ) ;
F_9 ( & V_26 , V_2 -> V_34 , F_10 ( V_2 -> V_34 ) ,
V_44 | V_43 ) ;
F_11 ( & V_25 ) ;
F_11 ( & V_26 ) ;
if ( ! V_25 . V_45 || ! V_26 . V_45 ) {
F_6 ( V_8 -> V_31 , L_3 ) ;
V_18 = - V_32 ;
goto V_46;
}
V_20 = V_2 -> V_21 / 4 ;
V_22 = V_2 -> V_21 / 4 ;
V_27 = 0 ;
V_28 = 0 ;
do {
V_23 = F_12 ( V_13 , V_20 , ( V_25 . V_47 - V_27 ) / 4 ) ;
if ( V_23 > 0 ) {
V_20 -= V_23 ;
F_13 ( V_8 -> V_38 + V_48 , V_25 . V_45 + V_27 , V_23 ) ;
V_27 += V_23 * 4 ;
}
if ( V_27 == V_25 . V_47 ) {
F_11 ( & V_25 ) ;
V_27 = 0 ;
}
V_16 = F_14 ( V_8 -> V_38 + V_49 ) ;
V_13 = F_15 ( V_16 ) ;
V_15 = F_16 ( V_16 ) ;
V_23 = F_12 ( V_15 , V_22 , ( V_26 . V_47 - V_28 ) / 4 ) ;
if ( V_23 > 0 ) {
V_22 -= V_23 ;
F_17 ( V_8 -> V_38 + V_50 , V_26 . V_45 + V_28 , V_23 ) ;
V_28 += V_23 * 4 ;
}
if ( V_28 == V_26 . V_47 ) {
F_11 ( & V_26 ) ;
V_28 = 0 ;
}
} while ( V_22 > 0 );
if ( V_2 -> V_30 ) {
for ( V_19 = 0 ; V_19 < 4 && V_19 < V_9 / 4 ; V_19 ++ ) {
V_17 = F_14 ( V_8 -> V_38 + V_40 + V_19 * 4 ) ;
* ( T_1 * ) ( V_2 -> V_30 + V_19 * 4 ) = V_17 ;
}
}
V_46:
F_18 ( & V_25 ) ;
F_18 ( & V_26 ) ;
F_8 ( 0 , V_8 -> V_38 + V_41 ) ;
F_19 ( & V_8 -> V_35 , V_29 ) ;
return V_18 ;
}
static int F_20 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
int V_51 = 1 ;
struct V_52 * V_53 = V_2 -> V_33 ;
struct V_52 * V_54 = V_2 -> V_34 ;
unsigned int V_9 = F_4 ( V_4 ) ;
struct V_10 * V_11 = F_5 ( V_2 ) ;
T_1 V_12 = V_11 -> V_12 ;
T_1 V_13 = V_14 ;
T_1 V_15 = 0 ;
T_1 V_17 ;
T_1 V_16 ;
int V_18 = 0 ;
unsigned int V_19 ;
unsigned int V_20 = V_2 -> V_21 ;
unsigned int V_22 = V_2 -> V_21 ;
unsigned int V_23 ;
struct V_24 V_25 , V_26 ;
unsigned int V_27 , V_28 ;
char V_55 [ 4 * V_56 ] ;
char V_57 [ 4 * V_58 ] ;
unsigned int V_59 = 0 ;
unsigned int V_60 = 0 ;
unsigned int V_61 = 0 ;
unsigned long V_29 ;
if ( V_2 -> V_21 == 0 )
return 0 ;
if ( ! V_2 -> V_30 ) {
F_6 ( V_8 -> V_31 , L_1 ) ;
return - V_32 ;
}
if ( ! V_2 -> V_33 || ! V_2 -> V_34 ) {
F_6 ( V_8 -> V_31 , L_2 ) ;
return - V_32 ;
}
while ( V_53 && V_51 == 1 ) {
if ( ( V_53 -> V_47 % 4 ) != 0 )
V_51 = 0 ;
V_53 = F_21 ( V_53 ) ;
}
while ( V_54 && V_51 == 1 ) {
if ( ( V_54 -> V_47 % 4 ) != 0 )
V_51 = 0 ;
V_54 = F_21 ( V_54 ) ;
}
if ( V_51 == 1 )
return F_1 ( V_2 ) ;
F_7 ( & V_8 -> V_35 , V_29 ) ;
for ( V_19 = 0 ; V_19 < V_6 -> V_36 ; V_19 += 4 )
F_8 ( * ( V_6 -> V_37 + V_19 / 4 ) , V_8 -> V_38 + V_39 + V_19 ) ;
if ( V_2 -> V_30 ) {
for ( V_19 = 0 ; V_19 < 4 && V_19 < V_9 / 4 ; V_19 ++ ) {
V_17 = * ( T_1 * ) ( V_2 -> V_30 + V_19 * 4 ) ;
F_8 ( V_17 , V_8 -> V_38 + V_40 + V_19 * 4 ) ;
}
}
F_8 ( V_12 , V_8 -> V_38 + V_41 ) ;
F_9 ( & V_25 , V_2 -> V_33 , F_10 ( V_2 -> V_33 ) ,
V_42 | V_43 ) ;
F_9 ( & V_26 , V_2 -> V_34 , F_10 ( V_2 -> V_34 ) ,
V_44 | V_43 ) ;
F_11 ( & V_25 ) ;
F_11 ( & V_26 ) ;
if ( ! V_25 . V_45 || ! V_26 . V_45 ) {
F_6 ( V_8 -> V_31 , L_3 ) ;
V_18 = - V_32 ;
goto V_46;
}
V_20 = V_2 -> V_21 ;
V_22 = V_2 -> V_21 ;
V_27 = 0 ;
V_28 = 0 ;
while ( V_22 > 0 ) {
if ( V_20 > 0 ) {
V_23 = F_12 ( V_13 , V_20 / 4 , ( V_25 . V_47 - V_27 ) / 4 ) ;
if ( V_23 > 0 && V_59 == 0 ) {
F_13 ( V_8 -> V_38 + V_48 , V_25 . V_45 + V_27 ,
V_23 ) ;
V_20 -= V_23 * 4 ;
V_27 += V_23 * 4 ;
} else {
V_23 = F_12 ( V_13 * 4 - V_59 , V_20 ,
V_25 . V_47 - V_27 ) ;
memcpy ( V_55 + V_59 , V_25 . V_45 + V_27 , V_23 ) ;
V_20 -= V_23 ;
V_27 += V_23 ;
V_59 += V_23 ;
if ( V_59 % 4 == 0 ) {
F_13 ( V_8 -> V_38 + V_48 , V_55 ,
V_59 / 4 ) ;
V_59 = 0 ;
}
}
if ( V_27 == V_25 . V_47 ) {
F_11 ( & V_25 ) ;
V_27 = 0 ;
}
}
V_16 = F_14 ( V_8 -> V_38 + V_49 ) ;
V_13 = F_15 ( V_16 ) ;
V_15 = F_16 ( V_16 ) ;
F_22 ( V_8 -> V_31 , L_4 ,
V_12 ,
V_27 , V_25 . V_47 , V_20 , V_2 -> V_21 , V_13 ,
V_28 , V_26 . V_47 , V_22 , V_2 -> V_21 , V_15 , V_59 ) ;
if ( V_15 == 0 )
continue;
V_23 = F_12 ( V_15 , V_22 / 4 , ( V_26 . V_47 - V_28 ) / 4 ) ;
if ( V_23 > 0 ) {
F_17 ( V_8 -> V_38 + V_50 , V_26 . V_45 + V_28 , V_23 ) ;
V_22 -= V_23 * 4 ;
V_28 += V_23 * 4 ;
if ( V_28 == V_26 . V_47 ) {
F_11 ( & V_26 ) ;
V_28 = 0 ;
}
} else {
F_17 ( V_8 -> V_38 + V_50 , V_57 , V_15 ) ;
V_61 = V_15 * 4 ;
V_60 = 0 ;
do {
V_23 = F_23 ( V_26 . V_47 - V_28 , V_61 - V_60 ) ;
memcpy ( V_26 . V_45 + V_28 , V_57 + V_60 , V_23 ) ;
V_22 -= V_23 ;
V_60 += V_23 ;
V_28 += V_23 ;
if ( V_28 == V_26 . V_47 ) {
F_11 ( & V_26 ) ;
V_28 = 0 ;
}
} while ( V_60 < V_61 );
}
}
if ( V_2 -> V_30 ) {
for ( V_19 = 0 ; V_19 < 4 && V_19 < V_9 / 4 ; V_19 ++ ) {
V_17 = F_14 ( V_8 -> V_38 + V_40 + V_19 * 4 ) ;
* ( T_1 * ) ( V_2 -> V_30 + V_19 * 4 ) = V_17 ;
}
}
V_46:
F_18 ( & V_25 ) ;
F_18 ( & V_26 ) ;
F_8 ( 0 , V_8 -> V_38 + V_41 ) ;
F_19 ( & V_8 -> V_35 , V_29 ) ;
return V_18 ;
}
int F_24 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
struct V_10 * V_62 = F_5 ( V_2 ) ;
V_62 -> V_12 = V_63 | V_64 | V_65 | V_66 |
V_6 -> V_67 ;
return F_20 ( V_2 ) ;
}
int F_25 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
struct V_10 * V_62 = F_5 ( V_2 ) ;
V_62 -> V_12 = V_63 | V_64 | V_65 | V_68 |
V_6 -> V_67 ;
return F_20 ( V_2 ) ;
}
int F_26 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
struct V_10 * V_62 = F_5 ( V_2 ) ;
V_62 -> V_12 = V_63 | V_69 | V_65 | V_66 |
V_6 -> V_67 ;
return F_20 ( V_2 ) ;
}
int F_27 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
struct V_10 * V_62 = F_5 ( V_2 ) ;
V_62 -> V_12 = V_63 | V_69 | V_65 | V_68 |
V_6 -> V_67 ;
return F_20 ( V_2 ) ;
}
int F_28 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
struct V_10 * V_62 = F_5 ( V_2 ) ;
V_62 -> V_12 = V_70 | V_64 | V_65 | V_66 |
V_6 -> V_67 ;
return F_20 ( V_2 ) ;
}
int F_29 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
struct V_10 * V_62 = F_5 ( V_2 ) ;
V_62 -> V_12 = V_70 | V_64 | V_65 | V_68 |
V_6 -> V_67 ;
return F_20 ( V_2 ) ;
}
int F_30 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
struct V_10 * V_62 = F_5 ( V_2 ) ;
V_62 -> V_12 = V_70 | V_69 | V_65 | V_66 |
V_6 -> V_67 ;
return F_20 ( V_2 ) ;
}
int F_31 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
struct V_10 * V_62 = F_5 ( V_2 ) ;
V_62 -> V_12 = V_70 | V_69 | V_65 | V_68 |
V_6 -> V_67 ;
return F_20 ( V_2 ) ;
}
int F_32 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
struct V_10 * V_62 = F_5 ( V_2 ) ;
V_62 -> V_12 = V_71 | V_64 | V_65 | V_66 |
V_6 -> V_67 ;
return F_20 ( V_2 ) ;
}
int F_33 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
struct V_10 * V_62 = F_5 ( V_2 ) ;
V_62 -> V_12 = V_71 | V_64 | V_65 | V_68 |
V_6 -> V_67 ;
return F_20 ( V_2 ) ;
}
int F_34 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
struct V_10 * V_62 = F_5 ( V_2 ) ;
V_62 -> V_12 = V_71 | V_69 | V_65 | V_66 |
V_6 -> V_67 ;
return F_20 ( V_2 ) ;
}
int F_35 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
struct V_10 * V_62 = F_5 ( V_2 ) ;
V_62 -> V_12 = V_71 | V_69 | V_65 | V_68 |
V_6 -> V_67 ;
return F_20 ( V_2 ) ;
}
int F_36 ( struct V_72 * V_4 )
{
struct V_5 * V_6 = F_37 ( V_4 ) ;
struct V_73 * V_74 = V_4 -> V_75 ;
struct V_76 * V_77 ;
memset ( V_6 , 0 , sizeof( struct V_5 ) ) ;
V_77 = F_38 ( V_74 , struct V_76 , V_74 . V_78 ) ;
V_6 -> V_8 = V_77 -> V_8 ;
V_4 -> V_79 . V_80 = sizeof( struct V_10 ) ;
return 0 ;
}
int F_39 ( struct V_3 * V_4 , const T_2 * V_37 ,
unsigned int V_36 )
{
struct V_5 * V_6 = F_3 ( V_4 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
switch ( V_36 ) {
case 128 / 8 :
V_6 -> V_67 = V_81 ;
break;
case 192 / 8 :
V_6 -> V_67 = V_82 ;
break;
case 256 / 8 :
V_6 -> V_67 = V_83 ;
break;
default:
F_40 ( V_8 -> V_31 , L_5 , V_36 ) ;
F_41 ( V_4 , V_84 ) ;
return - V_32 ;
}
V_6 -> V_36 = V_36 ;
memcpy ( V_6 -> V_37 , V_37 , V_36 ) ;
return 0 ;
}
int F_42 ( struct V_3 * V_4 , const T_2 * V_37 ,
unsigned int V_36 )
{
struct V_5 * V_6 = F_3 ( V_4 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
T_1 V_29 ;
T_1 V_85 [ V_86 ] ;
int V_87 ;
if ( F_43 ( V_36 != V_88 ) ) {
F_40 ( V_8 -> V_31 , L_6 , V_36 ) ;
F_41 ( V_4 , V_84 ) ;
return - V_32 ;
}
V_29 = F_44 ( V_4 ) ;
V_87 = F_45 ( V_85 , V_37 ) ;
if ( F_43 ( V_87 == 0 ) && ( V_29 & V_89 ) ) {
F_41 ( V_4 , V_90 ) ;
F_22 ( V_8 -> V_31 , L_7 , V_36 ) ;
return - V_32 ;
}
V_6 -> V_36 = V_36 ;
memcpy ( V_6 -> V_37 , V_37 , V_36 ) ;
return 0 ;
}
int F_46 ( struct V_3 * V_4 , const T_2 * V_37 ,
unsigned int V_36 )
{
struct V_5 * V_6 = F_3 ( V_4 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
if ( F_43 ( V_36 != 3 * V_88 ) ) {
F_40 ( V_8 -> V_31 , L_6 , V_36 ) ;
F_41 ( V_4 , V_84 ) ;
return - V_32 ;
}
V_6 -> V_36 = V_36 ;
memcpy ( V_6 -> V_37 , V_37 , V_36 ) ;
return 0 ;
}
