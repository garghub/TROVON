static T_1
F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
unsigned long V_5 ;
int V_6 ;
F_2 ( & V_4 -> V_7 , V_5 ) ;
F_3 ( & V_4 -> V_8 ) ;
V_6 = F_4 ( V_4 -> V_9 , V_4 -> V_10 ) ;
if ( V_6 > 0 ) {
if ( V_6 & V_11 ) {
F_5 ( & V_4 -> V_12 ) ;
}
if ( V_6 & V_13 ) {
F_6
( V_4 -> V_9 , V_4 -> V_10 ,
V_13 ) ;
F_5 ( & V_4 -> V_14 ) ;
}
}
F_7 ( & V_4 -> V_8 ) ;
F_8 ( & V_4 -> V_7 , V_5 ) ;
return V_15 ;
}
static int
F_9 ( struct V_16 * V_16 , struct V_17 * V_17 )
{
struct V_18 * V_19 ;
struct V_3 * V_4 ;
int V_20 ;
V_19 = F_10 ( V_16 -> V_21 , struct V_18 , V_22 ) ;
V_4 = F_11 ( sizeof ( struct V_3 ) , V_23 ) ;
if ( V_4 == NULL ) {
F_12 ( L_1 ,
V_24 ) ;
return - V_25 ;
}
V_4 -> V_9 = V_19 -> V_26 ;
V_4 -> V_10 = F_13 ( V_19 -> V_26 ) ;
if ( V_4 -> V_10 < 0 ) {
F_14 ( V_4 ) ;
F_12 ( L_2 , V_24 ) ;
return - V_27 ;
}
F_15 ( & V_4 -> V_7 ) ;
F_15 ( & V_4 -> V_8 ) ;
F_16 ( & V_4 -> V_12 ) ;
F_16 ( & V_4 -> V_14 ) ;
F_17 ( & V_4 -> V_28 , 1 ) ;
F_17 ( & V_4 -> V_29 , 1 ) ;
V_17 -> V_30 = V_4 ;
F_18 ( & V_31 ) ;
V_20 = F_19 ( V_32 , F_1 ,
V_33 | V_34 ,
V_35 , V_4 ) ;
if ( V_20 ) {
F_20 ( V_4 -> V_9 , V_4 -> V_10 ) ;
F_14 ( V_4 ) ;
F_12 ( L_3 , V_24 , V_20 ) ;
F_21 ( & V_31 ) ;
return - V_27 ;
}
F_21 ( & V_31 ) ;
return 0 ;
}
static int
F_22 ( struct V_16 * V_16 , struct V_17 * V_17 )
{
struct V_3 * V_4 = (struct V_3 * ) V_17 -> V_30 ;
int V_20 ;
F_23 ( V_32 , V_4 ) ;
V_20 = F_20 ( V_4 -> V_9 , V_4 -> V_10 ) ;
F_14 ( V_4 ) ;
return V_20 ;
}
static inline int
F_24 ( struct V_3 * V_4 , int * V_36 )
{
return F_25 ( V_4 -> V_9 , V_4 -> V_10 , V_4 -> V_37 , V_36 ) ;
}
static T_2
F_26 ( struct V_17 * V_17 , char T_3 * V_38 , T_4 V_39 , T_5 * V_40 )
{
int V_6 ;
int V_36 ;
unsigned long V_5 ;
struct V_3 * V_4 = (struct V_3 * ) V_17 -> V_30 ;
if ( F_27 ( & V_4 -> V_28 ) ) {
if ( V_17 -> V_41 & V_42 ) {
return - V_43 ;
}
if ( F_28 ( & V_4 -> V_28 ) ) {
return - V_44 ;
}
}
V_36 = V_45 ;
F_2 ( & V_4 -> V_7 , V_5 ) ;
V_6 = F_24 ( V_4 , & V_36 ) ;
while ( V_6 < 0 ) {
F_29 ( V_46 , V_47 ) ;
if ( V_17 -> V_41 & V_42 ) {
F_8 ( & V_4 -> V_7 , V_5 ) ;
F_30 ( & V_4 -> V_28 ) ;
return - V_43 ;
}
V_36 = V_45 ;
F_31 ( V_48 ) ;
F_32 ( & V_4 -> V_12 , & V_46 ) ;
F_8 ( & V_4 -> V_7 , V_5 ) ;
F_33 ( V_49 ) ;
F_34 ( & V_4 -> V_12 , & V_46 ) ;
if ( F_35 ( V_47 ) ) {
F_30 ( & V_4 -> V_28 ) ;
return - V_44 ;
}
F_2 ( & V_4 -> V_7 , V_5 ) ;
V_6 = F_24 ( V_4 , & V_36 ) ;
}
F_8 ( & V_4 -> V_7 , V_5 ) ;
if ( V_36 > 0 ) {
if ( V_39 < V_36 ) {
F_36 ( L_4 ,
V_24 , ( int ) V_39 , V_36 ) ;
}
V_36 = F_37 ( ( int ) V_39 , V_36 ) ;
if ( F_38 ( V_38 , V_4 -> V_37 , V_36 ) )
V_36 = - V_50 ;
}
F_30 ( & V_4 -> V_28 ) ;
return V_36 ;
}
static inline int
F_39 ( struct V_3 * V_4 , int V_39 )
{
return F_40 ( V_4 -> V_9 , V_4 -> V_10 , V_4 -> V_51 , V_39 ) ;
}
static T_2
F_41 ( struct V_17 * V_17 , const char T_3 * V_38 ,
T_4 V_39 , T_5 * V_40 )
{
unsigned long V_5 ;
int V_6 ;
struct V_3 * V_4 = (struct V_3 * ) V_17 -> V_30 ;
if ( F_27 ( & V_4 -> V_29 ) ) {
if ( V_17 -> V_41 & V_42 ) {
return - V_43 ;
}
if ( F_28 ( & V_4 -> V_29 ) ) {
return - V_44 ;
}
}
V_39 = F_37 ( ( int ) V_39 , V_45 ) ;
if ( F_42 ( V_4 -> V_51 , V_38 , V_39 ) ) {
F_30 ( & V_4 -> V_29 ) ;
return - V_50 ;
}
F_2 ( & V_4 -> V_8 , V_5 ) ;
V_6 = F_39 ( V_4 , V_39 ) ;
while ( V_6 <= 0 ) {
F_29 ( V_46 , V_47 ) ;
if ( V_17 -> V_41 & V_42 ) {
F_7 ( & V_4 -> V_8 ) ;
F_30 ( & V_4 -> V_29 ) ;
return - V_43 ;
}
F_31 ( V_48 ) ;
F_32 ( & V_4 -> V_14 , & V_46 ) ;
F_8 ( & V_4 -> V_8 , V_5 ) ;
F_33 ( V_49 ) ;
F_34 ( & V_4 -> V_14 , & V_46 ) ;
if ( F_35 ( V_47 ) ) {
F_30 ( & V_4 -> V_29 ) ;
return - V_44 ;
}
F_2 ( & V_4 -> V_8 , V_5 ) ;
V_6 = F_39 ( V_4 , V_39 ) ;
}
F_8 ( & V_4 -> V_8 , V_5 ) ;
F_30 ( & V_4 -> V_29 ) ;
if ( ( V_6 >= 0 ) && ( V_6 < V_39 ) ) {
F_36 ( L_5 ,
V_6 , ( int ) V_39 ) ;
}
return V_6 ;
}
static unsigned int
F_43 ( struct V_17 * V_17 , struct V_52 * V_46 )
{
unsigned int V_53 = 0 ;
int V_6 = 0 ;
struct V_3 * V_4 = (struct V_3 * ) V_17 -> V_30 ;
unsigned long V_5 ;
F_44 ( V_17 , & V_4 -> V_12 , V_46 ) ;
F_44 ( V_17 , & V_4 -> V_14 , V_46 ) ;
F_2 ( & V_4 -> V_7 , V_5 ) ;
F_3 ( & V_4 -> V_8 ) ;
V_6 = F_4 ( V_4 -> V_9 , V_4 -> V_10 ) ;
F_7 ( & V_4 -> V_8 ) ;
F_8 ( & V_4 -> V_7 , V_5 ) ;
if ( V_6 > 0 ) {
if ( V_6 & V_11 ) {
V_53 |= V_54 | V_55 ;
}
if ( V_6 & V_13 ) {
V_53 |= V_56 | V_57 ;
}
}
return V_53 ;
}
int T_6
F_45 ( void )
{
T_7 V_58 ;
T_8 V_59 ;
char V_60 [ 32 ] ;
char * V_61 ;
struct V_18 * V_19 ;
void * V_62 ;
T_9 V_63 , V_64 ;
T_10 V_65 ;
if ( ! F_46 ( L_6 ) )
return - V_66 ;
V_65 = F_47 () ;
if ( F_48 ( & V_63 , 0 , V_67 ,
V_35 ) < 0 ) {
F_12 ( L_7 ,
V_24 ) ;
return - V_66 ;
}
V_68 = F_49 ( V_69 , V_35 ) ;
for ( V_59 = 0 ; V_59 < V_67 ; V_59 ++ ) {
V_58 = F_50 ( V_59 ) ;
V_61 = V_60 ;
F_51 ( V_61 , F_52 ( V_58 ) ,
V_70 ) ;
V_61 = V_60 + strlen ( V_60 ) ;
sprintf ( V_61 , L_8 , F_53 ( V_58 ) ,
F_54 ( V_58 ) ) ;
V_19 = F_11 ( sizeof ( struct V_18 ) ,
V_23 ) ;
if ( ! V_19 ) {
F_12 ( L_9
L_10 , V_24 ,
V_35 , V_60 ) ;
continue;
}
V_19 -> V_26 = F_55 ( V_59 ) ;
if ( ! ( V_62 = F_56 ( V_71 , V_23 ) ) ) {
F_12 ( L_11
L_12 , V_24 ,
V_35 , V_60 ) ;
F_14 ( V_19 ) ;
continue;
}
if ( F_57 ( V_19 -> V_26 , V_62 ,
V_71 ) < 0 ) {
F_12
( L_13
L_14
L_15 ,
V_24 , V_35 , V_60 ) ;
F_14 ( V_19 ) ;
F_14 ( V_62 ) ;
continue;
}
V_64 = V_63 + V_59 ;
F_58 ( & V_19 -> V_22 , & V_72 ) ;
if ( F_59 ( & V_19 -> V_22 , V_64 , 1 ) ) {
F_12 ( L_16
L_17 ,
V_24 , V_35 , V_60 ) ;
F_14 ( V_19 ) ;
F_14 ( V_62 ) ;
continue;
}
F_60 ( V_68 , NULL , V_64 , NULL ,
L_18 , V_60 ) ;
F_61 ( V_19 -> V_26 ,
0 ,
V_11 ) ;
if( V_19 -> V_26 == V_65 ) {
F_62 ( V_19 ) ;
}
}
return 0 ;
}
