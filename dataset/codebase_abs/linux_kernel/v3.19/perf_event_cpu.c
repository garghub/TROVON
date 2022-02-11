const char * F_1 ( void )
{
if ( ! V_1 )
return NULL ;
return V_1 -> V_2 ;
}
int F_2 ( void )
{
int V_3 = 0 ;
if ( V_1 != NULL )
V_3 = V_1 -> V_4 ;
return V_3 ;
}
static void F_3 ( void * V_5 )
{
int V_6 = * ( int * ) V_5 ;
F_4 ( V_6 , V_7 ) ;
}
static void F_5 ( void * V_5 )
{
int V_6 = * ( int * ) V_5 ;
F_6 ( V_6 ) ;
}
static void F_7 ( struct V_8 * V_1 )
{
int V_9 , V_6 , V_10 ;
struct V_11 * V_12 = V_1 -> V_13 ;
struct V_14 T_1 * V_15 = V_1 -> V_15 ;
V_10 = F_8 ( V_12 -> V_16 , F_9 () ) ;
V_6 = F_10 ( V_12 , 0 ) ;
if ( V_6 >= 0 && F_11 ( V_6 ) ) {
F_12 ( F_5 , & V_6 , 1 ) ;
F_13 ( V_6 , & V_15 -> V_17 ) ;
} else {
for ( V_9 = 0 ; V_9 < V_10 ; ++ V_9 ) {
if ( ! F_14 ( V_9 , & V_1 -> V_18 ) )
continue;
V_6 = F_10 ( V_12 , V_9 ) ;
if ( V_6 >= 0 )
F_15 ( V_6 , F_16 ( & V_15 -> V_17 , V_9 ) ) ;
}
}
}
static int F_17 ( struct V_8 * V_1 , T_2 V_19 )
{
int V_9 , V_20 , V_6 , V_10 ;
struct V_11 * V_12 = V_1 -> V_13 ;
struct V_14 T_1 * V_15 = V_1 -> V_15 ;
if ( ! V_12 )
return - V_21 ;
V_10 = F_8 ( V_12 -> V_16 , F_9 () ) ;
if ( V_10 < 1 ) {
F_18 ( L_1 ) ;
return 0 ;
}
V_6 = F_10 ( V_12 , 0 ) ;
if ( V_6 >= 0 && F_11 ( V_6 ) ) {
V_20 = F_19 ( V_6 , V_19 , L_2 ,
& V_15 -> V_17 ) ;
if ( V_20 ) {
F_20 ( L_3 ,
V_6 ) ;
return V_20 ;
}
F_12 ( F_3 , & V_6 , 1 ) ;
} else {
for ( V_9 = 0 ; V_9 < V_10 ; ++ V_9 ) {
V_20 = 0 ;
V_6 = F_10 ( V_12 , V_9 ) ;
if ( V_6 < 0 )
continue;
if ( F_21 ( V_6 , F_22 ( V_9 ) ) && V_10 > 1 ) {
F_23 ( L_4 ,
V_6 , V_9 ) ;
continue;
}
V_20 = F_24 ( V_6 , V_19 ,
V_22 | V_23 , L_2 ,
F_16 ( & V_15 -> V_17 , V_9 ) ) ;
if ( V_20 ) {
F_20 ( L_3 ,
V_6 ) ;
return V_20 ;
}
F_25 ( V_9 , & V_1 -> V_18 ) ;
}
}
return 0 ;
}
static int F_26 ( struct V_24 * V_25 , unsigned long V_26 ,
void * V_27 )
{
struct V_8 * V_28 = F_27 ( V_25 , struct V_8 , V_29 ) ;
if ( ( V_26 & ~ V_30 ) != V_31 )
return V_32 ;
if ( V_28 -> V_33 )
V_28 -> V_33 ( V_28 ) ;
else
return V_32 ;
return V_34 ;
}
static int F_28 ( struct V_8 * V_1 )
{
int V_20 ;
int V_35 ;
struct V_14 T_1 * V_36 ;
V_36 = F_29 ( struct V_14 ) ;
if ( ! V_36 )
return - V_37 ;
V_1 -> V_29 . V_38 = F_26 ;
V_20 = F_30 ( & V_1 -> V_29 ) ;
if ( V_20 )
goto V_39;
F_31 (cpu) {
struct V_14 * V_40 = F_16 ( V_36 , V_35 ) ;
F_32 ( & V_40 -> V_41 ) ;
V_40 -> V_17 = V_1 ;
}
V_1 -> V_15 = V_36 ;
V_1 -> F_24 = F_17 ;
V_1 -> F_15 = F_7 ;
if ( V_1 -> V_33 )
F_12 ( V_1 -> V_33 , V_1 , 1 ) ;
if ( ! F_10 ( V_1 -> V_13 , 0 ) )
V_1 -> V_28 . V_42 |= V_43 ;
return 0 ;
V_39:
F_33 ( V_36 ) ;
return V_20 ;
}
static void F_34 ( struct V_8 * V_1 )
{
F_35 ( & V_1 -> V_29 ) ;
F_33 ( V_1 -> V_15 ) ;
}
static int F_36 ( struct V_8 * V_28 )
{
int V_35 = F_37 () ;
unsigned int V_44 = F_38 () ;
int V_45 = - V_21 ;
const struct V_46 * V_47 ;
F_39 ( L_5 , V_35 ) ;
for ( V_47 = V_48 ; V_47 -> V_49 != NULL ; V_47 ++ ) {
if ( ( V_44 & V_47 -> V_50 ) != V_47 -> V_44 )
continue;
V_45 = V_47 -> V_49 ( V_28 ) ;
break;
}
F_40 () ;
return V_45 ;
}
static int F_41 ( struct V_11 * V_51 )
{
const struct V_52 * V_53 ;
const int (* F_42)( struct V_8 * );
struct V_54 * V_55 = V_51 -> V_56 . V_57 ;
struct V_8 * V_28 ;
int V_45 = - V_21 ;
if ( V_1 ) {
F_39 ( L_6 ) ;
return - V_58 ;
}
V_28 = F_43 ( sizeof( struct V_8 ) , V_59 ) ;
if ( ! V_28 ) {
F_39 ( L_7 ) ;
return - V_37 ;
}
V_1 = V_28 ;
V_1 -> V_13 = V_51 ;
if ( V_55 && ( V_53 = F_44 ( V_60 , V_51 -> V_56 . V_57 ) ) ) {
F_42 = V_53 -> V_5 ;
V_45 = F_42 ( V_28 ) ;
} else {
V_45 = F_36 ( V_28 ) ;
}
if ( V_45 ) {
F_39 ( L_8 ) ;
goto V_61;
}
V_45 = F_28 ( V_1 ) ;
if ( V_45 )
goto V_61;
V_45 = F_45 ( V_1 , - 1 ) ;
if ( V_45 )
goto V_62;
return 0 ;
V_62:
F_34 ( V_1 ) ;
V_61:
F_39 ( L_9 ) ;
F_46 ( V_28 ) ;
return V_45 ;
}
static int T_3 F_47 ( void )
{
return F_48 ( & V_63 ) ;
}
