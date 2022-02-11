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
struct V_8 * V_1 = V_7 ;
struct V_9 * V_10 = V_1 -> V_11 ;
int V_12 = F_6 ( V_10 , 0 ) ;
F_7 ( V_12 , V_13 ) ;
F_8 ( F_9 () , & V_1 -> V_14 ) ;
}
static void F_10 ( void * V_7 )
{
struct V_8 * V_1 = V_7 ;
struct V_9 * V_10 = V_1 -> V_11 ;
int V_12 = F_6 ( V_10 , 0 ) ;
F_11 ( F_9 () , & V_1 -> V_14 ) ;
F_12 ( V_12 ) ;
}
static void F_13 ( struct V_8 * V_1 )
{
int V_15 , V_12 , V_16 ;
struct V_9 * V_10 = V_1 -> V_11 ;
V_16 = F_14 ( V_10 -> V_17 , F_15 () ) ;
V_12 = F_6 ( V_10 , 0 ) ;
if ( V_12 >= 0 && F_16 ( V_12 ) ) {
F_17 ( F_10 , V_1 , 1 ) ;
F_18 ( V_12 , & V_18 ) ;
} else {
for ( V_15 = 0 ; V_15 < V_16 ; ++ V_15 ) {
if ( ! F_19 ( V_15 , & V_1 -> V_14 ) )
continue;
V_12 = F_6 ( V_10 , V_15 ) ;
if ( V_12 >= 0 )
F_20 ( V_12 , V_1 ) ;
}
}
}
static int F_21 ( struct V_8 * V_1 , T_1 V_19 )
{
int V_15 , V_20 , V_12 , V_16 ;
struct V_9 * V_10 = V_1 -> V_11 ;
if ( ! V_10 )
return - V_21 ;
V_16 = F_14 ( V_10 -> V_17 , F_15 () ) ;
if ( V_16 < 1 ) {
F_22 ( L_1 ) ;
return - V_21 ;
}
V_12 = F_6 ( V_10 , 0 ) ;
if ( V_12 >= 0 && F_16 ( V_12 ) ) {
V_20 = F_23 ( V_12 , V_19 , L_2 , & V_18 ) ;
if ( V_20 ) {
F_22 ( L_3 ,
V_12 ) ;
return V_20 ;
}
F_17 ( F_5 , V_1 , 1 ) ;
} else {
for ( V_15 = 0 ; V_15 < V_16 ; ++ V_15 ) {
V_20 = 0 ;
V_12 = F_6 ( V_10 , V_15 ) ;
if ( V_12 < 0 )
continue;
if ( F_24 ( V_12 , F_25 ( V_15 ) ) && V_16 > 1 ) {
F_26 ( L_4 ,
V_12 , V_15 ) ;
continue;
}
V_20 = F_27 ( V_12 , V_19 ,
V_22 | V_23 , L_2 ,
V_1 ) ;
if ( V_20 ) {
F_22 ( L_3 ,
V_12 ) ;
return V_20 ;
}
F_8 ( V_15 , & V_1 -> V_14 ) ;
}
}
return 0 ;
}
static void F_28 ( struct V_8 * V_1 )
{
int V_24 ;
F_29 (cpu) {
struct V_5 * V_25 = & F_30 ( V_6 , V_24 ) ;
V_25 -> V_25 = F_30 ( V_26 , V_24 ) ;
V_25 -> V_27 = F_30 ( V_27 , V_24 ) ;
F_31 ( & V_25 -> V_28 ) ;
F_30 ( V_18 , V_24 ) = V_1 ;
}
V_1 -> V_29 = F_3 ;
V_1 -> F_27 = F_21 ;
V_1 -> F_20 = F_13 ;
if ( V_1 -> V_30 )
F_17 ( V_1 -> V_30 , V_1 , 1 ) ;
}
static int F_32 ( struct V_31 * V_32 , unsigned long V_33 ,
void * V_34 )
{
if ( ( V_33 & ~ V_35 ) != V_36 )
return V_37 ;
if ( V_1 && V_1 -> V_30 )
V_1 -> V_30 ( V_1 ) ;
else
return V_37 ;
return V_38 ;
}
static int F_33 ( struct V_8 * V_39 )
{
int V_24 = F_34 () ;
unsigned long V_40 = F_35 () ;
unsigned long V_41 = F_36 () ;
int V_42 = - V_21 ;
F_37 ( L_5 , V_24 ) ;
if ( V_40 == V_43 ) {
switch ( V_41 ) {
case V_44 :
case V_45 :
case V_46 :
V_42 = F_38 ( V_39 ) ;
break;
case V_47 :
V_42 = F_39 ( V_39 ) ;
break;
case V_48 :
V_42 = F_40 ( V_39 ) ;
break;
case V_49 :
V_42 = F_41 ( V_39 ) ;
break;
}
} else if ( V_40 == V_50 ) {
switch ( F_42 () ) {
case V_51 :
V_42 = F_43 ( V_39 ) ;
break;
case V_52 :
V_42 = F_44 ( V_39 ) ;
break;
}
}
F_45 () ;
return V_42 ;
}
static int F_46 ( struct V_9 * V_53 )
{
const struct V_54 * V_55 ;
const int (* F_47)( struct V_8 * );
struct V_56 * V_57 = V_53 -> V_58 . V_59 ;
struct V_8 * V_39 ;
int V_42 = - V_21 ;
if ( V_1 ) {
F_37 ( L_6 ) ;
return - V_60 ;
}
V_39 = F_48 ( sizeof( struct V_8 ) , V_61 ) ;
if ( ! V_39 ) {
F_37 ( L_7 ) ;
return - V_62 ;
}
V_1 = V_39 ;
V_1 -> V_11 = V_53 ;
if ( V_57 && ( V_55 = F_49 ( V_63 , V_53 -> V_58 . V_59 ) ) ) {
F_47 = V_55 -> V_7 ;
V_42 = F_47 ( V_39 ) ;
} else {
V_42 = F_33 ( V_39 ) ;
}
if ( V_42 ) {
F_37 ( L_8 ) ;
goto V_64;
}
F_28 ( V_1 ) ;
V_42 = F_50 ( V_1 , V_65 ) ;
if ( ! V_42 )
return 0 ;
V_64:
F_37 ( L_9 ) ;
F_51 ( V_39 ) ;
return V_42 ;
}
static int T_2 F_52 ( void )
{
int V_20 ;
V_20 = F_53 ( & V_66 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_54 ( & V_67 ) ;
if ( V_20 )
F_55 ( & V_66 ) ;
return V_20 ;
}
