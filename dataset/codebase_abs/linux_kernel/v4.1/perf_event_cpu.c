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
int V_18 = V_9 ;
if ( V_1 -> V_19 )
V_18 = V_1 -> V_19 [ V_9 ] ;
if ( ! F_14 ( V_18 , & V_1 -> V_20 ) )
continue;
V_6 = F_10 ( V_12 , V_9 ) ;
if ( V_6 >= 0 )
F_15 ( V_6 , F_16 ( & V_15 -> V_17 , V_18 ) ) ;
}
}
}
static int F_17 ( struct V_8 * V_1 , T_2 V_21 )
{
int V_9 , V_22 , V_6 , V_10 ;
struct V_11 * V_12 = V_1 -> V_13 ;
struct V_14 T_1 * V_15 = V_1 -> V_15 ;
if ( ! V_12 )
return - V_23 ;
V_10 = F_8 ( V_12 -> V_16 , F_9 () ) ;
if ( V_10 < 1 ) {
F_18 ( L_1 ) ;
return 0 ;
}
V_6 = F_10 ( V_12 , 0 ) ;
if ( V_6 >= 0 && F_11 ( V_6 ) ) {
V_22 = F_19 ( V_6 , V_21 , L_2 ,
& V_15 -> V_17 ) ;
if ( V_22 ) {
F_20 ( L_3 ,
V_6 ) ;
return V_22 ;
}
F_12 ( F_3 , & V_6 , 1 ) ;
} else {
for ( V_9 = 0 ; V_9 < V_10 ; ++ V_9 ) {
int V_18 = V_9 ;
V_22 = 0 ;
V_6 = F_10 ( V_12 , V_9 ) ;
if ( V_6 < 0 )
continue;
if ( V_1 -> V_19 )
V_18 = V_1 -> V_19 [ V_9 ] ;
if ( F_21 ( V_6 , F_22 ( V_18 ) ) && V_10 > 1 ) {
F_23 ( L_4 ,
V_6 , V_18 ) ;
continue;
}
V_22 = F_24 ( V_6 , V_21 ,
V_24 | V_25 , L_2 ,
F_16 ( & V_15 -> V_17 , V_18 ) ) ;
if ( V_22 ) {
F_20 ( L_3 ,
V_6 ) ;
return V_22 ;
}
F_25 ( V_18 , & V_1 -> V_20 ) ;
}
}
return 0 ;
}
static int F_26 ( struct V_26 * V_27 , unsigned long V_28 ,
void * V_29 )
{
struct V_8 * V_30 = F_27 ( V_27 , struct V_8 , V_31 ) ;
if ( ( V_28 & ~ V_32 ) != V_33 )
return V_34 ;
if ( V_30 -> V_35 )
V_30 -> V_35 ( V_30 ) ;
else
return V_34 ;
return V_36 ;
}
static int F_28 ( struct V_8 * V_1 )
{
int V_22 ;
int V_18 ;
struct V_14 T_1 * V_37 ;
V_37 = F_29 ( struct V_14 ) ;
if ( ! V_37 )
return - V_38 ;
V_1 -> V_31 . V_39 = F_26 ;
V_22 = F_30 ( & V_1 -> V_31 ) ;
if ( V_22 )
goto V_40;
F_31 (cpu) {
struct V_14 * V_41 = F_16 ( V_37 , V_18 ) ;
F_32 ( & V_41 -> V_42 ) ;
V_41 -> V_17 = V_1 ;
}
V_1 -> V_15 = V_37 ;
V_1 -> F_24 = F_17 ;
V_1 -> F_15 = F_7 ;
if ( V_1 -> V_35 )
F_12 ( V_1 -> V_35 , V_1 , 1 ) ;
if ( ! F_10 ( V_1 -> V_13 , 0 ) )
V_1 -> V_30 . V_43 |= V_44 ;
return 0 ;
V_40:
F_33 ( V_37 ) ;
return V_22 ;
}
static void F_34 ( struct V_8 * V_1 )
{
F_35 ( & V_1 -> V_31 ) ;
F_33 ( V_1 -> V_15 ) ;
}
static int F_36 ( struct V_8 * V_30 )
{
int V_18 = F_37 () ;
unsigned int V_45 = F_38 () ;
int V_46 = - V_23 ;
const struct V_47 * V_48 ;
F_39 ( L_5 , V_18 ) ;
for ( V_48 = V_49 ; V_48 -> V_50 != NULL ; V_48 ++ ) {
if ( ( V_45 & V_48 -> V_51 ) != V_48 -> V_45 )
continue;
V_46 = V_48 -> V_50 ( V_30 ) ;
break;
}
F_40 () ;
return V_46 ;
}
static int F_41 ( struct V_11 * V_52 )
{
int V_9 , V_6 ;
int * V_10 ;
V_6 = F_10 ( V_52 , 0 ) ;
if ( V_6 >= 0 && F_11 ( V_6 ) )
return 0 ;
V_10 = F_42 ( V_52 -> V_16 , sizeof( * V_10 ) , V_53 ) ;
if ( ! V_10 )
return - V_38 ;
for ( V_9 = 0 ; V_9 < V_52 -> V_16 ; ++ V_9 ) {
struct V_54 * V_55 ;
int V_18 ;
V_55 = F_43 ( V_52 -> V_56 . V_57 , L_6 ,
V_9 ) ;
if ( ! V_55 ) {
F_23 ( L_7 ,
F_44 ( V_52 -> V_56 . V_57 ) , V_9 ) ;
break;
}
F_31 (cpu)
if ( F_45 ( V_55 , V_18 , NULL ) )
break;
F_46 ( V_55 ) ;
if ( V_18 >= V_58 ) {
F_23 ( L_8 ,
V_55 -> V_2 ) ;
break;
}
V_10 [ V_9 ] = V_18 ;
}
if ( V_9 == V_52 -> V_16 )
V_1 -> V_19 = V_10 ;
else
F_47 ( V_10 ) ;
return 0 ;
}
static int F_48 ( struct V_11 * V_52 )
{
const struct V_59 * V_60 ;
const int (* F_49)( struct V_8 * );
struct V_54 * V_61 = V_52 -> V_56 . V_57 ;
struct V_8 * V_30 ;
int V_46 = - V_23 ;
if ( V_1 ) {
F_39 ( L_9 ) ;
return - V_62 ;
}
V_30 = F_50 ( sizeof( struct V_8 ) , V_53 ) ;
if ( ! V_30 ) {
F_39 ( L_10 ) ;
return - V_38 ;
}
V_1 = V_30 ;
V_1 -> V_13 = V_52 ;
if ( V_61 && ( V_60 = F_51 ( V_63 , V_52 -> V_56 . V_57 ) ) ) {
F_49 = V_60 -> V_5 ;
V_46 = F_41 ( V_52 ) ;
if ( ! V_46 )
V_46 = F_49 ( V_30 ) ;
} else {
V_46 = F_36 ( V_30 ) ;
}
if ( V_46 ) {
F_39 ( L_11 ) ;
goto V_64;
}
V_46 = F_28 ( V_1 ) ;
if ( V_46 )
goto V_64;
V_46 = F_52 ( V_1 , - 1 ) ;
if ( V_46 )
goto V_65;
return 0 ;
V_65:
F_34 ( V_1 ) ;
V_64:
F_39 ( L_12 ) ;
F_47 ( V_30 ) ;
return V_46 ;
}
static int T_3 F_53 ( void )
{
return F_54 ( & V_66 ) ;
}
