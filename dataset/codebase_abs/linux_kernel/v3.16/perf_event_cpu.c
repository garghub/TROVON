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
return 0 ;
}
V_12 = F_6 ( V_10 , 0 ) ;
if ( V_12 >= 0 && F_16 ( V_12 ) ) {
V_20 = F_23 ( V_12 , V_19 , L_2 , & V_18 ) ;
if ( V_20 ) {
F_24 ( L_3 ,
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
if ( F_25 ( V_12 , F_26 ( V_15 ) ) && V_16 > 1 ) {
F_27 ( L_4 ,
V_12 , V_15 ) ;
continue;
}
V_20 = F_28 ( V_12 , V_19 ,
V_22 | V_23 , L_2 ,
V_1 ) ;
if ( V_20 ) {
F_24 ( L_3 ,
V_12 ) ;
return V_20 ;
}
F_8 ( V_15 , & V_1 -> V_14 ) ;
}
}
return 0 ;
}
static void F_29 ( struct V_8 * V_1 )
{
int V_24 ;
F_30 (cpu) {
struct V_5 * V_25 = & F_31 ( V_6 , V_24 ) ;
V_25 -> V_25 = F_31 ( V_26 , V_24 ) ;
V_25 -> V_27 = F_31 ( V_27 , V_24 ) ;
F_32 ( & V_25 -> V_28 ) ;
F_31 ( V_18 , V_24 ) = V_1 ;
}
V_1 -> V_29 = F_3 ;
V_1 -> F_28 = F_21 ;
V_1 -> F_20 = F_13 ;
if ( V_1 -> V_30 )
F_17 ( V_1 -> V_30 , V_1 , 1 ) ;
if ( ! F_6 ( V_1 -> V_11 , 0 ) )
V_1 -> V_31 . V_32 |= V_33 ;
}
static int F_33 ( struct V_34 * V_35 , unsigned long V_36 ,
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
static int F_34 ( struct V_8 * V_31 )
{
int V_24 = F_35 () ;
unsigned long V_42 = F_36 () ;
unsigned long V_43 = F_37 () ;
int V_44 = - V_21 ;
F_38 ( L_5 , V_24 ) ;
if ( V_42 == V_45 ) {
switch ( V_43 ) {
case V_46 :
case V_47 :
case V_48 :
V_44 = F_39 ( V_31 ) ;
break;
case V_49 :
V_44 = F_40 ( V_31 ) ;
break;
case V_50 :
V_44 = F_41 ( V_31 ) ;
break;
case V_51 :
V_44 = F_42 ( V_31 ) ;
break;
}
} else if ( V_42 == V_52 ) {
switch ( F_43 () ) {
case V_53 :
V_44 = F_44 ( V_31 ) ;
break;
case V_54 :
V_44 = F_45 ( V_31 ) ;
break;
}
}
F_46 () ;
return V_44 ;
}
static int F_47 ( struct V_9 * V_55 )
{
const struct V_56 * V_57 ;
const int (* F_48)( struct V_8 * );
struct V_58 * V_59 = V_55 -> V_60 . V_61 ;
struct V_8 * V_31 ;
int V_44 = - V_21 ;
if ( V_1 ) {
F_38 ( L_6 ) ;
return - V_62 ;
}
V_31 = F_49 ( sizeof( struct V_8 ) , V_63 ) ;
if ( ! V_31 ) {
F_38 ( L_7 ) ;
return - V_64 ;
}
V_1 = V_31 ;
V_1 -> V_11 = V_55 ;
if ( V_59 && ( V_57 = F_50 ( V_65 , V_55 -> V_60 . V_61 ) ) ) {
F_48 = V_57 -> V_7 ;
V_44 = F_48 ( V_31 ) ;
} else {
V_44 = F_34 ( V_31 ) ;
}
if ( V_44 ) {
F_38 ( L_8 ) ;
goto V_66;
}
F_29 ( V_1 ) ;
V_44 = F_51 ( V_1 , V_67 ) ;
if ( ! V_44 )
return 0 ;
V_66:
F_38 ( L_9 ) ;
F_52 ( V_31 ) ;
return V_44 ;
}
static int T_2 F_53 ( void )
{
int V_20 ;
V_20 = F_54 ( & V_68 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_55 ( & V_69 ) ;
if ( V_20 )
F_56 ( & V_68 ) ;
return V_20 ;
}
