static int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 , unsigned int V_4 )
{
if ( V_2 -> V_5 < V_3 )
return - V_6 ;
if ( V_2 -> V_7 < V_4 )
return - V_8 ;
V_2 -> V_9 += V_3 ;
V_2 -> V_5 -= V_3 ;
V_2 -> V_10 += V_4 ;
V_2 -> V_7 -= V_4 ;
V_2 -> V_11 += V_4 ;
return 0 ;
}
int F_2 ( struct V_12 * V_13 , struct V_14 * V_15 )
{
struct V_16 * V_17 = F_3 ( V_13 ) ;
F_4 ( & V_17 -> V_18 ) ;
V_17 -> V_15 = V_15 ;
V_17 -> V_19 = F_5 ( V_15 -> V_20 , V_21 ) ;
V_17 -> V_22 = ( V_23 * ) F_6 ( V_21 , V_24 ) ;
V_17 -> V_25 = ( V_23 * ) F_6 ( V_21 , V_24 ) ;
if ( ! V_17 -> V_19 || ! V_17 -> V_22 || ! V_17 -> V_25 ) {
F_7 ( V_17 -> V_19 ) ;
F_8 ( ( unsigned long ) V_17 -> V_22 ) ;
F_8 ( ( unsigned long ) V_17 -> V_25 ) ;
return - V_26 ;
}
return 0 ;
}
void F_9 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = F_3 ( V_13 ) ;
F_7 ( V_17 -> V_19 ) ;
F_8 ( ( unsigned long ) V_17 -> V_22 ) ;
F_8 ( ( unsigned long ) V_17 -> V_25 ) ;
}
static void F_10 ( struct V_27 * V_28 )
{
if ( V_28 -> V_29 > V_30 )
V_28 -> V_29 = V_30 ;
}
static int F_11 ( struct V_31 * V_32 , V_23 * V_33 )
{
int V_34 = F_12 ( V_32 -> V_35 ) ;
if ( V_34 > F_13 ( V_32 -> V_36 [ 0 ] . V_37 ) ) {
F_14 ( L_1 ) ;
return - V_38 ;
}
memcpy ( V_33 , V_32 , V_34 ) ;
F_15 ( L_2 , V_39 , 16 , 1 , V_33 , V_34 , 0 ) ;
return 0 ;
}
static int F_16 ( struct V_16 * V_17 ,
struct V_1 * V_2 ,
struct V_40 * V_41 ,
struct V_27 * V_28 ,
T_1 * V_42 ,
unsigned int V_43 )
{
unsigned int V_3 = V_2 -> V_5 , V_4 = V_2 -> V_7 , V_44 ;
unsigned int V_45 = V_3 ;
V_23 * V_46 = V_2 -> V_9 , * V_47 = V_2 -> V_10 ;
int V_48 , V_49 = 0 ;
T_2 V_50 ;
if ( V_2 -> V_5 == 0 )
return - V_6 ;
if ( V_2 -> V_7 == 0 || V_43 + V_28 -> V_51 > V_4 )
return - V_8 ;
if ( V_3 % V_28 -> V_52 )
V_45 = F_17 ( V_3 , V_28 -> V_52 ) ;
if ( V_3 < V_28 -> V_51 )
V_45 = V_28 -> V_51 ;
if ( V_3 > V_28 -> V_29 )
V_45 = V_3 = V_28 -> V_29 ;
if ( V_45 > V_3 || ( V_53 ) V_46 % V_28 -> V_54 ) {
V_45 = F_18 ( V_45 , V_30 ) ;
V_3 = F_18 ( V_3 , V_30 ) ;
if ( V_45 > V_3 )
memset ( V_17 -> V_22 + V_3 , 0 , V_45 - V_3 ) ;
memcpy ( V_17 -> V_22 , V_46 , V_3 ) ;
V_46 = V_17 -> V_22 ;
V_3 = V_45 ;
F_19 ( L_3 , V_3 ) ;
}
V_47 += V_43 ;
V_4 -= V_43 ;
if ( ( V_53 ) V_47 % V_28 -> V_54 ) {
V_49 = ( int ) ( F_20 ( V_47 , V_28 -> V_54 ) - V_47 ) ;
V_47 += V_49 ;
V_4 -= V_49 ;
}
if ( V_4 % V_28 -> V_52 )
V_4 = F_21 ( V_4 , V_28 -> V_52 ) ;
if ( V_4 < V_28 -> V_51 ) {
V_55:
V_47 = V_17 -> V_25 ;
V_4 = F_18 ( V_2 -> V_7 , V_30 ) ;
V_4 = F_21 ( V_4 , V_28 -> V_52 ) ;
V_49 = 0 ;
F_19 ( L_4 , V_4 ) ;
}
if ( V_4 > V_28 -> V_29 )
V_4 = V_28 -> V_29 ;
V_44 = V_4 ;
V_50 = F_22 ( F_23 () , V_56 ) ;
do {
V_4 = V_44 ;
V_48 = V_17 -> V_15 -> F_16 ( V_46 , V_3 , V_47 , & V_4 , V_17 -> V_19 ) ;
if ( V_48 == - V_8 && V_47 != V_17 -> V_25 )
goto V_55;
} while ( V_48 == - V_57 && F_24 ( F_23 () , V_50 ) );
if ( V_48 )
return V_48 ;
V_49 += V_43 ;
if ( V_47 == V_17 -> V_25 )
memcpy ( V_2 -> V_10 + V_49 , V_47 , V_4 ) ;
V_41 -> V_37 = F_25 ( V_49 ) ;
V_41 -> V_58 = F_26 ( V_4 ) ;
V_41 -> V_59 = F_26 ( V_3 ) ;
if ( V_2 -> V_5 < V_3 ) {
* V_42 = V_3 - V_2 -> V_5 ;
V_3 = V_2 -> V_5 ;
}
F_19 ( L_5 ,
V_3 , * V_42 , V_4 , V_49 ) ;
return F_1 ( V_2 , V_3 , V_49 + V_4 ) ;
}
int F_27 ( struct V_12 * V_13 ,
const V_23 * V_46 , unsigned int V_3 ,
V_23 * V_47 , unsigned int * V_4 )
{
struct V_16 * V_17 = F_3 ( V_13 ) ;
struct V_31 * V_32 = & V_17 -> V_60 ;
struct V_1 V_2 ;
struct V_27 V_28 = * V_17 -> V_15 -> V_61 ;
unsigned int V_35 , V_43 , V_62 ;
int V_48 , V_63 ;
bool V_64 ;
T_1 V_42 = 0 ;
F_10 ( & V_28 ) ;
V_2 . V_9 = ( V_23 * ) V_46 ;
V_2 . V_5 = V_3 ;
V_2 . V_10 = V_47 ;
V_2 . V_7 = * V_4 ;
V_2 . V_11 = 0 ;
* V_4 = 0 ;
V_35 = F_28 (unsigned int, NX842_CRYPTO_GROUP_MAX,
DIV_ROUND_UP(p.iremain, c.maximum)) ;
V_43 = F_12 ( V_35 ) ;
F_29 ( & V_17 -> V_18 ) ;
V_64 = ( V_2 . V_5 % V_28 . V_52 ||
V_2 . V_5 < V_28 . V_51 ||
V_2 . V_5 > V_28 . V_29 ||
( V_53 ) V_2 . V_9 % V_28 . V_54 ||
V_2 . V_7 % V_28 . V_52 ||
V_2 . V_7 < V_28 . V_51 ||
V_2 . V_7 > V_28 . V_29 ||
( V_53 ) V_2 . V_10 % V_28 . V_54 ) ;
V_32 -> V_65 = F_25 ( V_66 ) ;
V_32 -> V_35 = 0 ;
V_32 -> V_42 = 0 ;
while ( V_2 . V_5 > 0 ) {
V_63 = V_32 -> V_35 ++ ;
V_48 = - V_8 ;
if ( V_32 -> V_35 > V_67 )
goto V_68;
V_62 = ! V_63 && V_64 ? V_43 : 0 ;
if ( V_42 )
F_30 ( L_6 , V_42 ) ;
V_48 = F_16 ( V_17 , & V_2 , & V_32 -> V_36 [ V_63 ] , & V_28 , & V_42 , V_62 ) ;
if ( V_48 )
goto V_68;
}
if ( ! V_64 && V_32 -> V_35 > 1 ) {
F_14 ( L_7 ) ;
V_48 = - V_38 ;
goto V_68;
}
V_32 -> V_42 = F_25 ( V_42 ) ;
if ( V_42 )
F_19 ( L_8 , V_42 ) ;
if ( V_64 )
V_48 = F_11 ( V_32 , V_47 ) ;
if ( V_48 )
goto V_68;
* V_4 = V_2 . V_11 ;
F_19 ( L_9 , V_3 , * V_4 ) ;
V_68:
F_31 ( & V_17 -> V_18 ) ;
return V_48 ;
}
static int F_32 ( struct V_16 * V_17 ,
struct V_1 * V_2 ,
struct V_40 * V_41 ,
struct V_27 * V_28 ,
T_1 V_42 )
{
unsigned int V_3 = F_33 ( V_41 -> V_58 ) ;
unsigned int V_69 = F_33 ( V_41 -> V_59 ) ;
unsigned int V_4 = V_2 -> V_7 , V_44 ;
unsigned int V_45 = V_3 ;
V_23 * V_46 = V_2 -> V_9 , * V_47 = V_2 -> V_10 ;
T_1 V_37 = F_13 ( V_41 -> V_37 ) ;
int V_48 , V_70 = 0 , V_71 = 0 ;
T_2 V_50 ;
if ( ! V_3 || ! V_69 )
return - V_38 ;
if ( V_2 -> V_5 <= 0 || V_37 + V_3 > V_2 -> V_5 )
return - V_6 ;
if ( V_2 -> V_7 <= 0 || V_69 - V_42 > V_2 -> V_7 )
return - V_8 ;
V_46 += V_37 ;
if ( V_3 % V_28 -> V_52 )
V_45 = F_17 ( V_3 , V_28 -> V_52 ) ;
if ( V_3 < V_28 -> V_51 )
V_45 = V_28 -> V_51 ;
if ( V_3 > V_28 -> V_29 )
goto V_72;
if ( V_3 < V_45 || ( V_53 ) V_46 % V_28 -> V_54 ) {
if ( V_3 < V_45 )
memset ( V_17 -> V_22 + V_3 , 0 , V_45 - V_3 ) ;
memcpy ( V_17 -> V_22 , V_46 , V_3 ) ;
V_46 = V_17 -> V_22 ;
V_70 = V_45 - V_3 ;
V_3 = V_45 ;
F_19 ( L_10 , V_3 ) ;
}
if ( V_4 % V_28 -> V_52 )
V_4 = F_21 ( V_4 , V_28 -> V_52 ) ;
if ( V_4 < V_69 || ( V_53 ) V_47 % V_28 -> V_54 ) {
V_47 = V_17 -> V_25 ;
V_4 = F_18 ( V_69 , V_30 ) ;
F_19 ( L_11 , V_4 ) ;
}
if ( V_4 < V_28 -> V_51 )
goto V_72;
if ( V_4 > V_28 -> V_29 )
V_4 = V_28 -> V_29 ;
V_44 = V_4 ;
V_50 = F_22 ( F_23 () , V_73 ) ;
do {
V_4 = V_44 ;
V_48 = V_17 -> V_15 -> F_32 ( V_46 , V_3 , V_47 , & V_4 , V_17 -> V_19 ) ;
} while ( V_48 == - V_57 && F_24 ( F_23 () , V_50 ) );
if ( V_48 ) {
V_72:
V_46 = V_2 -> V_9 + V_37 ;
V_3 = F_33 ( V_41 -> V_58 ) ;
V_70 = 0 ;
V_47 = V_2 -> V_10 ;
V_4 = V_2 -> V_7 ;
V_71 = 0 ;
if ( V_4 < V_69 ) {
V_47 = V_17 -> V_25 ;
V_4 = V_30 ;
}
F_34 ( L_12 ) ;
V_48 = F_35 ( V_46 , V_3 , V_47 , & V_4 ) ;
}
if ( V_48 )
return V_48 ;
V_3 -= V_70 ;
V_4 -= V_42 ;
if ( V_42 )
F_19 ( L_13 , V_42 ) ;
if ( V_47 == V_17 -> V_25 )
memcpy ( V_2 -> V_10 , V_47 , V_4 ) ;
F_19 ( L_14 ,
V_3 , V_37 , V_4 , V_42 ) ;
return F_1 ( V_2 , V_3 + V_37 , V_4 ) ;
}
int F_36 ( struct V_12 * V_13 ,
const V_23 * V_46 , unsigned int V_3 ,
V_23 * V_47 , unsigned int * V_4 )
{
struct V_16 * V_17 = F_3 ( V_13 ) ;
struct V_31 * V_32 ;
struct V_1 V_2 ;
struct V_27 V_28 = * V_17 -> V_15 -> V_61 ;
int V_63 , V_48 , V_74 ;
T_1 V_42 = 0 ;
F_10 ( & V_28 ) ;
V_2 . V_9 = ( V_23 * ) V_46 ;
V_2 . V_5 = V_3 ;
V_2 . V_10 = V_47 ;
V_2 . V_7 = * V_4 ;
V_2 . V_11 = 0 ;
* V_4 = 0 ;
V_32 = (struct V_31 * ) V_46 ;
F_29 ( & V_17 -> V_18 ) ;
if ( F_13 ( V_32 -> V_65 ) != V_66 ) {
struct V_40 V_41 = {
. V_37 = 0 ,
. V_58 = F_26 ( V_2 . V_5 ) ,
. V_59 = F_26 ( V_2 . V_7 ) ,
} ;
V_48 = F_32 ( V_17 , & V_2 , & V_41 , & V_28 , 0 ) ;
if ( V_48 )
goto V_68;
goto V_75;
}
if ( ! V_32 -> V_35 ) {
F_14 ( L_15 ) ;
V_48 = - V_38 ;
goto V_68;
}
if ( V_32 -> V_35 > V_67 ) {
F_14 ( L_16 ,
V_32 -> V_35 , V_67 ) ;
V_48 = - V_38 ;
goto V_68;
}
V_74 = F_12 ( V_32 -> V_35 ) ;
if ( V_74 > V_3 ) {
V_48 = - V_6 ;
goto V_68;
}
memcpy ( & V_17 -> V_60 , V_46 , V_74 ) ;
V_32 = & V_17 -> V_60 ;
for ( V_63 = 0 ; V_63 < V_32 -> V_35 ; V_63 ++ ) {
if ( V_63 + 1 == V_32 -> V_35 )
V_42 = F_13 ( V_32 -> V_42 ) ;
V_48 = F_32 ( V_17 , & V_2 , & V_32 -> V_36 [ V_63 ] , & V_28 , V_42 ) ;
if ( V_48 )
goto V_68;
}
V_75:
* V_4 = V_2 . V_11 ;
F_19 ( L_17 , V_3 , * V_4 ) ;
V_48 = 0 ;
V_68:
F_31 ( & V_17 -> V_18 ) ;
return V_48 ;
}
