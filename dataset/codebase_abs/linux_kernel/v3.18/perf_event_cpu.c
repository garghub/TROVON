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
static struct V_5 * F_3 ( void )
{
return F_4 ( & V_6 ) ;
}
static void F_5 ( void * V_7 )
{
int V_8 = * ( int * ) V_7 ;
F_6 ( V_8 , V_9 ) ;
}
static void F_7 ( void * V_7 )
{
int V_8 = * ( int * ) V_7 ;
F_8 ( V_8 ) ;
}
static void F_9 ( struct V_10 * V_1 )
{
int V_11 , V_8 , V_12 ;
struct V_13 * V_14 = V_1 -> V_15 ;
V_12 = F_10 ( V_14 -> V_16 , F_11 () ) ;
V_8 = F_12 ( V_14 , 0 ) ;
if ( V_8 >= 0 && F_13 ( V_8 ) ) {
F_14 ( F_7 , & V_8 , 1 ) ;
F_15 ( V_8 , & V_17 ) ;
} else {
for ( V_11 = 0 ; V_11 < V_12 ; ++ V_11 ) {
if ( ! F_16 ( V_11 , & V_1 -> V_18 ) )
continue;
V_8 = F_12 ( V_14 , V_11 ) ;
if ( V_8 >= 0 )
F_17 ( V_8 , V_1 ) ;
}
}
}
static int F_18 ( struct V_10 * V_1 , T_1 V_19 )
{
int V_11 , V_20 , V_8 , V_12 ;
struct V_13 * V_14 = V_1 -> V_15 ;
if ( ! V_14 )
return - V_21 ;
V_12 = F_10 ( V_14 -> V_16 , F_11 () ) ;
if ( V_12 < 1 ) {
F_19 ( L_1 ) ;
return 0 ;
}
V_8 = F_12 ( V_14 , 0 ) ;
if ( V_8 >= 0 && F_13 ( V_8 ) ) {
V_20 = F_20 ( V_8 , V_19 , L_2 , & V_17 ) ;
if ( V_20 ) {
F_21 ( L_3 ,
V_8 ) ;
return V_20 ;
}
F_14 ( F_5 , & V_8 , 1 ) ;
} else {
for ( V_11 = 0 ; V_11 < V_12 ; ++ V_11 ) {
V_20 = 0 ;
V_8 = F_12 ( V_14 , V_11 ) ;
if ( V_8 < 0 )
continue;
if ( F_22 ( V_8 , F_23 ( V_11 ) ) && V_12 > 1 ) {
F_24 ( L_4 ,
V_8 , V_11 ) ;
continue;
}
V_20 = F_25 ( V_8 , V_19 ,
V_22 | V_23 , L_2 ,
V_1 ) ;
if ( V_20 ) {
F_21 ( L_3 ,
V_8 ) ;
return V_20 ;
}
F_26 ( V_11 , & V_1 -> V_18 ) ;
}
}
return 0 ;
}
static void F_27 ( struct V_10 * V_1 )
{
int V_24 ;
F_28 (cpu) {
struct V_5 * V_25 = & F_29 ( V_6 , V_24 ) ;
V_25 -> V_25 = F_29 ( V_26 , V_24 ) ;
V_25 -> V_27 = F_29 ( V_27 , V_24 ) ;
F_30 ( & V_25 -> V_28 ) ;
F_29 ( V_17 , V_24 ) = V_1 ;
}
V_1 -> V_29 = F_3 ;
V_1 -> F_25 = F_18 ;
V_1 -> F_17 = F_9 ;
if ( V_1 -> V_30 )
F_14 ( V_1 -> V_30 , V_1 , 1 ) ;
if ( ! F_12 ( V_1 -> V_15 , 0 ) )
V_1 -> V_31 . V_32 |= V_33 ;
}
static int F_31 ( struct V_34 * V_35 , unsigned long V_36 ,
void * V_37 )
{
if ( ( V_36 & ~ V_38 ) != V_39 )
return V_40 ;
if ( V_1 && V_1 -> V_30 )
V_1 -> V_30 ( V_1 ) ;
else
return V_40 ;
return V_41 ;
}
static int F_32 ( struct V_10 * V_31 )
{
int V_24 = F_33 () ;
int V_42 = - V_21 ;
F_34 ( L_5 , V_24 ) ;
switch ( F_35 () ) {
case V_43 :
V_42 = F_36 ( V_31 ) ;
break;
case V_44 :
V_42 = F_37 ( V_31 ) ;
break;
case V_45 :
V_42 = F_38 ( V_31 ) ;
break;
case V_46 :
V_42 = F_39 ( V_31 ) ;
break;
case V_47 :
V_42 = F_40 ( V_31 ) ;
break;
case V_48 :
V_42 = F_41 ( V_31 ) ;
break;
default:
if ( F_42 () == V_49 ) {
switch ( F_43 () ) {
case V_50 :
V_42 = F_44 ( V_31 ) ;
break;
case V_51 :
V_42 = F_45 ( V_31 ) ;
break;
}
}
break;
}
F_46 () ;
return V_42 ;
}
static int F_47 ( struct V_13 * V_52 )
{
const struct V_53 * V_54 ;
const int (* F_48)( struct V_10 * );
struct V_55 * V_56 = V_52 -> V_57 . V_58 ;
struct V_10 * V_31 ;
int V_42 = - V_21 ;
if ( V_1 ) {
F_34 ( L_6 ) ;
return - V_59 ;
}
V_31 = F_49 ( sizeof( struct V_10 ) , V_60 ) ;
if ( ! V_31 ) {
F_34 ( L_7 ) ;
return - V_61 ;
}
V_1 = V_31 ;
V_1 -> V_15 = V_52 ;
if ( V_56 && ( V_54 = F_50 ( V_62 , V_52 -> V_57 . V_58 ) ) ) {
F_48 = V_54 -> V_7 ;
V_42 = F_48 ( V_31 ) ;
} else {
V_42 = F_32 ( V_31 ) ;
}
if ( V_42 ) {
F_34 ( L_8 ) ;
goto V_63;
}
F_27 ( V_1 ) ;
V_42 = F_51 ( V_1 , V_64 ) ;
if ( ! V_42 )
return 0 ;
V_63:
F_34 ( L_9 ) ;
F_52 ( V_31 ) ;
return V_42 ;
}
static int T_2 F_53 ( void )
{
int V_20 ;
V_20 = F_54 ( & V_65 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_55 ( & V_66 ) ;
if ( V_20 )
F_56 ( & V_65 ) ;
return V_20 ;
}
