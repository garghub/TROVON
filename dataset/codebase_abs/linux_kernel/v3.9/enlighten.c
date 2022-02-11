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
int V_14 = 0 ;
F_2 ( V_6 . V_15 , & V_12 ) ;
F_2 ( V_6 . V_16 , & V_13 ) ;
F_2 ( V_6 . V_17 , & V_14 ) ;
V_4 = F_3 ( V_18 , & V_6 ) ;
if ( V_4 || V_14 ) {
F_4 ( L_1 ,
V_4 , V_14 , V_1 , V_2 ) ;
return 1 ;
}
return 0 ;
}
static int F_5 ( T_3 * V_19 , T_4 V_20 , unsigned long V_21 ,
void * V_22 )
{
struct V_23 * V_24 = V_22 ;
struct V_25 * V_25 = V_24 -> V_26 [ V_24 -> V_27 ++ ] ;
unsigned long V_28 = F_6 ( V_25 ) ;
T_3 V_29 = F_7 ( V_28 , V_24 -> V_30 ) ;
if ( F_1 ( V_28 , V_24 -> V_2 , V_24 -> V_3 ) )
return - V_31 ;
F_8 ( V_24 -> V_32 -> V_33 , V_21 , V_19 , V_29 ) ;
return 0 ;
}
int F_9 ( struct V_34 * V_32 ,
unsigned long V_21 ,
T_2 V_35 , int V_36 ,
T_5 V_30 , unsigned V_3 ,
struct V_25 * * V_26 )
{
int V_14 ;
struct V_23 V_22 ;
if ( V_36 > 1 )
return - V_37 ;
V_22 . V_2 = V_35 ;
V_22 . V_30 = V_30 ;
V_22 . V_3 = V_3 ;
V_22 . V_32 = V_32 ;
V_22 . V_27 = 0 ;
V_22 . V_26 = V_26 ;
V_14 = F_10 ( V_32 -> V_33 , V_21 , V_36 << V_38 ,
F_5 , & V_22 ) ;
return V_14 ;
}
int F_11 ( struct V_34 * V_32 ,
int V_36 , struct V_25 * * V_26 )
{
int V_39 ;
for ( V_39 = 0 ; V_39 < V_36 ; V_39 ++ ) {
struct V_40 V_41 ;
unsigned long V_4 , V_28 ;
V_28 = F_6 ( V_26 [ V_39 ] ) ;
V_41 . V_3 = V_7 ;
V_41 . V_13 = V_28 ;
V_4 = F_3 ( V_42 , & V_41 ) ;
if ( V_4 ) {
F_4 ( L_2 ,
V_28 , V_4 ) ;
return V_4 ;
}
}
return 0 ;
}
static int T_6 F_12 ( void )
{
struct V_43 V_6 ;
static struct V_44 * V_45 = 0 ;
struct V_46 * V_47 ;
int V_48 ;
const char * V_49 = NULL ;
const char * V_50 = NULL ;
const char * V_51 = L_3 ;
struct V_52 V_53 ;
V_47 = F_13 ( NULL , NULL , L_4 ) ;
if ( ! V_47 ) {
F_14 ( L_5 ) ;
return 0 ;
}
V_49 = F_15 ( V_47 , L_6 , & V_48 ) ;
if ( strlen ( V_51 ) + 3 < V_48 &&
! strncmp ( V_51 , V_49 , strlen ( V_51 ) ) )
V_50 = V_49 + strlen ( V_51 ) ;
if ( V_50 == NULL ) {
F_14 ( L_7 ) ;
return 0 ;
}
if ( F_16 ( V_47 , V_54 , & V_53 ) )
return 0 ;
V_55 = V_53 . V_56 >> V_38 ;
V_57 = F_17 ( V_47 , 0 ) ;
F_18 ( L_8 ,
V_50 , V_57 , V_55 ) ;
V_58 = V_59 ;
F_19 () ;
if ( F_20 ( V_60 ) )
V_61 -> V_62 |= V_63 | V_64 ;
else
V_61 -> V_62 &= ~ ( V_63 | V_64 ) ;
if ( ! V_45 )
V_45 = (struct V_44 * )
F_21 ( V_65 ) ;
if ( ! V_45 ) {
F_22 ( L_9 ) ;
return - V_66 ;
}
V_6 . V_3 = V_7 ;
V_6 . V_12 = 0 ;
V_6 . V_10 = V_67 ;
V_6 . V_13 = F_23 ( V_45 ) >> V_38 ;
if ( F_3 ( V_68 , & V_6 ) )
F_24 () ;
V_69 = (struct V_44 * ) V_45 ;
F_25 ( V_70 , 0 ) = & V_69 -> V_71 [ 0 ] ;
F_26 () ;
if ( ! F_27 () )
F_28 ( NULL ) ;
return 0 ;
}
static T_7 F_29 ( int V_72 , void * V_73 )
{
F_30 () ;
return V_74 ;
}
static int T_6 F_31 ( void )
{
if ( ! F_32 () || V_57 < 0 )
return - V_75 ;
F_33 () ;
if ( F_34 ( V_57 , F_29 ,
L_10 , V_70 ) ) {
F_22 ( L_11 , V_57 ) ;
return - V_37 ;
}
F_35 ( V_57 , 0 ) ;
return 0 ;
}
