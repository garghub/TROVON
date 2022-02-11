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
V_33 , V_34 , V_4 ) ;
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
F_24 ( struct V_3 * V_4 , int * V_35 )
{
return F_25 ( V_4 -> V_9 , V_4 -> V_10 , V_4 -> V_36 , V_35 ) ;
}
static T_2
F_26 ( struct V_17 * V_17 , char T_3 * V_37 , T_4 V_38 , T_5 * V_39 )
{
int V_6 ;
int V_35 ;
unsigned long V_5 ;
struct V_3 * V_4 = (struct V_3 * ) V_17 -> V_30 ;
if ( F_27 ( & V_4 -> V_28 ) ) {
if ( V_17 -> V_40 & V_41 ) {
return - V_42 ;
}
if ( F_28 ( & V_4 -> V_28 ) ) {
return - V_43 ;
}
}
V_35 = V_44 ;
F_2 ( & V_4 -> V_7 , V_5 ) ;
V_6 = F_24 ( V_4 , & V_35 ) ;
while ( V_6 < 0 ) {
F_29 ( V_45 , V_46 ) ;
if ( V_17 -> V_40 & V_41 ) {
F_8 ( & V_4 -> V_7 , V_5 ) ;
F_30 ( & V_4 -> V_28 ) ;
return - V_42 ;
}
V_35 = V_44 ;
F_31 ( V_47 ) ;
F_32 ( & V_4 -> V_12 , & V_45 ) ;
F_8 ( & V_4 -> V_7 , V_5 ) ;
F_33 ( F_34 ( V_48 ) ) ;
F_35 ( & V_4 -> V_12 , & V_45 ) ;
if ( F_36 ( V_46 ) ) {
F_30 ( & V_4 -> V_28 ) ;
return - V_43 ;
}
F_2 ( & V_4 -> V_7 , V_5 ) ;
V_6 = F_24 ( V_4 , & V_35 ) ;
}
F_8 ( & V_4 -> V_7 , V_5 ) ;
if ( V_35 > 0 ) {
if ( V_38 < V_35 ) {
F_37 ( L_4 ,
V_24 , ( int ) V_38 , V_35 ) ;
}
V_35 = F_38 ( ( int ) V_38 , V_35 ) ;
if ( F_39 ( V_37 , V_4 -> V_36 , V_35 ) )
V_35 = - V_49 ;
}
F_30 ( & V_4 -> V_28 ) ;
return V_35 ;
}
static inline int
F_40 ( struct V_3 * V_4 , int V_38 )
{
return F_41 ( V_4 -> V_9 , V_4 -> V_10 , V_4 -> V_50 , V_38 ) ;
}
static T_2
F_42 ( struct V_17 * V_17 , const char T_3 * V_37 ,
T_4 V_38 , T_5 * V_39 )
{
unsigned long V_5 ;
int V_6 ;
struct V_3 * V_4 = (struct V_3 * ) V_17 -> V_30 ;
if ( F_27 ( & V_4 -> V_29 ) ) {
if ( V_17 -> V_40 & V_41 ) {
return - V_42 ;
}
if ( F_28 ( & V_4 -> V_29 ) ) {
return - V_43 ;
}
}
V_38 = F_38 ( ( int ) V_38 , V_44 ) ;
if ( F_43 ( V_4 -> V_50 , V_37 , V_38 ) ) {
F_30 ( & V_4 -> V_29 ) ;
return - V_49 ;
}
F_2 ( & V_4 -> V_8 , V_5 ) ;
V_6 = F_40 ( V_4 , V_38 ) ;
while ( V_6 <= 0 ) {
F_29 ( V_45 , V_46 ) ;
if ( V_17 -> V_40 & V_41 ) {
F_7 ( & V_4 -> V_8 ) ;
F_30 ( & V_4 -> V_29 ) ;
return - V_42 ;
}
F_31 ( V_47 ) ;
F_32 ( & V_4 -> V_14 , & V_45 ) ;
F_8 ( & V_4 -> V_8 , V_5 ) ;
F_33 ( F_34 ( V_48 ) ) ;
F_35 ( & V_4 -> V_14 , & V_45 ) ;
if ( F_36 ( V_46 ) ) {
F_30 ( & V_4 -> V_29 ) ;
return - V_43 ;
}
F_2 ( & V_4 -> V_8 , V_5 ) ;
V_6 = F_40 ( V_4 , V_38 ) ;
}
F_8 ( & V_4 -> V_8 , V_5 ) ;
F_30 ( & V_4 -> V_29 ) ;
if ( ( V_6 >= 0 ) && ( V_6 < V_38 ) ) {
F_37 ( L_5 ,
V_6 , ( int ) V_38 ) ;
}
return V_6 ;
}
static unsigned int
F_44 ( struct V_17 * V_17 , struct V_51 * V_45 )
{
unsigned int V_52 = 0 ;
int V_6 = 0 ;
struct V_3 * V_4 = (struct V_3 * ) V_17 -> V_30 ;
unsigned long V_5 ;
F_45 ( V_17 , & V_4 -> V_12 , V_45 ) ;
F_45 ( V_17 , & V_4 -> V_14 , V_45 ) ;
F_2 ( & V_4 -> V_7 , V_5 ) ;
F_3 ( & V_4 -> V_8 ) ;
V_6 = F_4 ( V_4 -> V_9 , V_4 -> V_10 ) ;
F_7 ( & V_4 -> V_8 ) ;
F_8 ( & V_4 -> V_7 , V_5 ) ;
if ( V_6 > 0 ) {
if ( V_6 & V_11 ) {
V_52 |= V_53 | V_54 ;
}
if ( V_6 & V_13 ) {
V_52 |= V_55 | V_56 ;
}
}
return V_52 ;
}
int T_6
F_46 ( void )
{
T_7 V_57 ;
T_8 V_58 ;
char V_59 [ 32 ] ;
char * V_60 ;
struct V_18 * V_19 ;
void * V_61 ;
T_9 V_62 , V_63 ;
T_10 V_64 ;
if ( ! F_47 ( L_6 ) )
return - V_65 ;
V_64 = F_48 () ;
V_66 = F_49 ( V_67 , V_34 ) ;
if ( F_50 ( V_66 ) ) {
F_12 ( L_7 , V_24 ) ;
return F_51 ( V_66 ) ;
}
if ( F_52 ( & V_62 , 0 , V_68 ,
V_34 ) < 0 ) {
F_12 ( L_8 ,
V_24 ) ;
return - V_65 ;
}
for ( V_58 = 0 ; V_58 < V_68 ; V_58 ++ ) {
V_57 = F_53 ( V_58 ) ;
V_60 = V_59 ;
F_54 ( V_60 , F_55 ( V_57 ) ,
V_69 ) ;
V_60 = V_59 + strlen ( V_59 ) ;
sprintf ( V_60 , L_9 , F_56 ( V_57 ) ,
F_57 ( V_57 ) ) ;
V_19 = F_11 ( sizeof ( struct V_18 ) ,
V_23 ) ;
if ( ! V_19 ) {
F_12 ( L_10
L_11 , V_24 ,
V_34 , V_59 ) ;
continue;
}
V_19 -> V_26 = F_58 ( V_58 ) ;
if ( ! ( V_61 = F_59 ( V_70 , V_23 ) ) ) {
F_12 ( L_12
L_13 , V_24 ,
V_34 , V_59 ) ;
F_14 ( V_19 ) ;
continue;
}
if ( F_60 ( V_19 -> V_26 , V_61 ,
V_70 ) < 0 ) {
F_12
( L_14
L_15
L_16 ,
V_24 , V_34 , V_59 ) ;
F_14 ( V_19 ) ;
F_14 ( V_61 ) ;
continue;
}
V_63 = V_62 + V_58 ;
F_61 ( & V_19 -> V_22 , & V_71 ) ;
if ( F_62 ( & V_19 -> V_22 , V_63 , 1 ) ) {
F_12 ( L_17
L_18 ,
V_24 , V_34 , V_59 ) ;
F_14 ( V_19 ) ;
F_14 ( V_61 ) ;
continue;
}
F_63 ( V_66 , NULL , V_63 , NULL ,
L_19 , V_59 ) ;
F_64 ( V_19 -> V_26 ,
0 ,
V_11 ) ;
if( V_19 -> V_26 == V_64 ) {
F_65 ( V_19 ) ;
}
}
return 0 ;
}
