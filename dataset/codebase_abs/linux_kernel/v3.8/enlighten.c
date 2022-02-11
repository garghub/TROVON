static int F_1 ( unsigned long V_1 , unsigned long V_2 ,
unsigned int V_3 )
{
int V_4 ;
struct V_5 V_6 = {
. V_3 = V_7 ,
. V_8 = V_3 ,
. V_9 = 1 ,
. V_10 = V_11 ,
} ;
T_1 V_12 = V_2 ;
T_2 V_13 = V_1 ;
F_2 ( V_6 . V_14 , & V_12 ) ;
F_2 ( V_6 . V_15 , & V_13 ) ;
V_4 = F_3 ( V_16 , & V_6 ) ;
if ( V_4 ) {
F_4 ( L_1 ,
V_4 , V_1 , V_2 ) ;
return 1 ;
}
return 0 ;
}
static int F_5 ( T_3 * V_17 , T_4 V_18 , unsigned long V_19 ,
void * V_20 )
{
struct V_21 * V_22 = V_20 ;
struct V_23 * V_23 = V_22 -> V_24 [ V_22 -> V_25 ++ ] ;
unsigned long V_26 = F_6 ( V_23 ) ;
T_3 V_27 = F_7 ( V_26 , V_22 -> V_28 ) ;
if ( F_1 ( V_26 , V_22 -> V_2 , V_22 -> V_3 ) )
return - V_29 ;
F_8 ( V_22 -> V_30 -> V_31 , V_19 , V_17 , V_27 ) ;
return 0 ;
}
int F_9 ( struct V_32 * V_30 ,
unsigned long V_19 ,
T_2 V_33 , int V_34 ,
T_5 V_28 , unsigned V_3 ,
struct V_23 * * V_24 )
{
int V_35 ;
struct V_21 V_20 ;
if ( V_34 > 1 )
return - V_36 ;
V_20 . V_2 = V_33 ;
V_20 . V_28 = V_28 ;
V_20 . V_3 = V_3 ;
V_20 . V_30 = V_30 ;
V_20 . V_25 = 0 ;
V_20 . V_24 = V_24 ;
V_35 = F_10 ( V_30 -> V_31 , V_19 , V_34 << V_37 ,
F_5 , & V_20 ) ;
return V_35 ;
}
int F_11 ( struct V_32 * V_30 ,
int V_34 , struct V_23 * * V_24 )
{
int V_38 ;
for ( V_38 = 0 ; V_38 < V_34 ; V_38 ++ ) {
struct V_39 V_40 ;
unsigned long V_4 , V_26 ;
V_26 = F_6 ( V_24 [ V_38 ] ) ;
V_40 . V_3 = V_7 ;
V_40 . V_13 = V_26 ;
V_4 = F_3 ( V_41 , & V_40 ) ;
if ( V_4 ) {
F_4 ( L_2 ,
V_26 , V_4 ) ;
return V_4 ;
}
}
return 0 ;
}
static int T_6 F_12 ( void )
{
struct V_42 V_6 ;
static struct V_43 * V_44 = 0 ;
struct V_45 * V_46 ;
int V_47 ;
const char * V_48 = NULL ;
const char * V_49 = NULL ;
const char * V_50 = L_3 ;
struct V_51 V_52 ;
V_46 = F_13 ( NULL , NULL , L_4 ) ;
if ( ! V_46 ) {
F_14 ( L_5 ) ;
return 0 ;
}
V_48 = F_15 ( V_46 , L_6 , & V_47 ) ;
if ( strlen ( V_50 ) + 3 < V_47 &&
! strncmp ( V_50 , V_48 , strlen ( V_50 ) ) )
V_49 = V_48 + strlen ( V_50 ) ;
if ( V_49 == NULL ) {
F_14 ( L_7 ) ;
return 0 ;
}
if ( F_16 ( V_46 , V_53 , & V_52 ) )
return 0 ;
V_54 = V_52 . V_55 >> V_37 ;
V_56 = F_17 ( V_46 , 0 ) ;
F_18 ( L_8 ,
V_49 , V_56 , V_54 ) ;
V_57 = V_58 ;
F_19 () ;
if ( F_20 ( V_59 ) )
V_60 -> V_61 |= V_62 | V_63 ;
else
V_60 -> V_61 &= ~ ( V_62 | V_63 ) ;
if ( ! V_44 )
V_44 = (struct V_43 * )
F_21 ( V_64 ) ;
if ( ! V_44 ) {
F_22 ( L_9 ) ;
return - V_65 ;
}
V_6 . V_3 = V_7 ;
V_6 . V_12 = 0 ;
V_6 . V_10 = V_66 ;
V_6 . V_13 = F_23 ( V_44 ) >> V_37 ;
if ( F_3 ( V_67 , & V_6 ) )
F_24 () ;
V_68 = (struct V_43 * ) V_44 ;
F_25 ( V_69 , 0 ) = & V_68 -> V_70 [ 0 ] ;
F_26 () ;
if ( ! F_27 () )
F_28 ( NULL ) ;
return 0 ;
}
static T_7 F_29 ( int V_71 , void * V_72 )
{
F_30 () ;
return V_73 ;
}
static int T_6 F_31 ( void )
{
if ( ! F_32 () || V_56 < 0 )
return - V_74 ;
F_33 () ;
if ( F_34 ( V_56 , F_29 ,
L_10 , V_69 ) ) {
F_22 ( L_11 , V_56 ) ;
return - V_36 ;
}
F_35 ( V_56 , 0 ) ;
return 0 ;
}
