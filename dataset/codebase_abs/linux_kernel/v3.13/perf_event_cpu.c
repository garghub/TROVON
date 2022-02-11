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
static void F_5 ( struct V_7 * V_1 )
{
int V_8 , V_9 , V_10 ;
struct V_11 * V_12 = V_1 -> V_13 ;
V_10 = F_6 ( V_12 -> V_14 , F_7 () ) ;
for ( V_8 = 0 ; V_8 < V_10 ; ++ V_8 ) {
if ( ! F_8 ( V_8 , & V_1 -> V_15 ) )
continue;
V_9 = F_9 ( V_12 , V_8 ) ;
if ( V_9 >= 0 )
F_10 ( V_9 , V_1 ) ;
}
}
static int F_11 ( struct V_7 * V_1 , T_1 V_16 )
{
int V_8 , V_17 , V_9 , V_10 ;
struct V_11 * V_12 = V_1 -> V_13 ;
if ( ! V_12 )
return - V_18 ;
V_10 = F_6 ( V_12 -> V_14 , F_7 () ) ;
if ( V_10 < 1 ) {
F_12 ( L_1 ) ;
return - V_18 ;
}
for ( V_8 = 0 ; V_8 < V_10 ; ++ V_8 ) {
V_17 = 0 ;
V_9 = F_9 ( V_12 , V_8 ) ;
if ( V_9 < 0 )
continue;
if ( F_13 ( V_9 , F_14 ( V_8 ) ) && V_10 > 1 ) {
F_15 ( L_2 ,
V_9 , V_8 ) ;
continue;
}
V_17 = F_16 ( V_9 , V_16 ,
V_19 | V_20 , L_3 ,
V_1 ) ;
if ( V_17 ) {
F_12 ( L_4 ,
V_9 ) ;
return V_17 ;
}
F_17 ( V_8 , & V_1 -> V_15 ) ;
}
return 0 ;
}
static void F_18 ( struct V_7 * V_1 )
{
int V_21 ;
F_19 (cpu) {
struct V_5 * V_22 = & F_20 ( V_6 , V_21 ) ;
V_22 -> V_22 = F_20 ( V_23 , V_21 ) ;
V_22 -> V_24 = F_20 ( V_24 , V_21 ) ;
F_21 ( & V_22 -> V_25 ) ;
}
V_1 -> V_26 = F_3 ;
V_1 -> F_16 = F_11 ;
V_1 -> F_10 = F_5 ;
if ( V_1 -> V_27 )
F_22 ( V_1 -> V_27 , V_1 , 1 ) ;
}
static int F_23 ( struct V_28 * V_29 , unsigned long V_30 ,
void * V_31 )
{
if ( ( V_30 & ~ V_32 ) != V_33 )
return V_34 ;
if ( V_1 && V_1 -> V_27 )
V_1 -> V_27 ( V_1 ) ;
else
return V_34 ;
return V_35 ;
}
static int F_24 ( struct V_7 * V_36 )
{
int V_21 = F_25 () ;
unsigned long V_37 = F_26 () ;
unsigned long V_38 = F_27 () ;
int V_39 = - V_18 ;
F_28 ( L_5 , V_21 ) ;
if ( V_37 == V_40 ) {
switch ( V_38 ) {
case V_41 :
case V_42 :
case V_43 :
V_39 = F_29 ( V_36 ) ;
break;
case V_44 :
V_39 = F_30 ( V_36 ) ;
break;
case V_45 :
V_39 = F_31 ( V_36 ) ;
break;
case V_46 :
V_39 = F_32 ( V_36 ) ;
break;
case V_47 :
V_39 = F_33 ( V_36 ) ;
break;
case V_48 :
V_39 = F_34 ( V_36 ) ;
break;
case V_49 :
V_39 = F_35 ( V_36 ) ;
break;
}
} else if ( V_37 == V_50 ) {
switch ( F_36 () ) {
case V_51 :
V_39 = F_37 ( V_36 ) ;
break;
case V_52 :
V_39 = F_38 ( V_36 ) ;
break;
}
}
F_39 () ;
return V_39 ;
}
static int F_40 ( struct V_11 * V_53 )
{
const struct V_54 * V_55 ;
const int (* F_41)( struct V_7 * );
struct V_56 * V_57 = V_53 -> V_58 . V_59 ;
struct V_7 * V_36 ;
int V_39 = - V_18 ;
if ( V_1 ) {
F_28 ( L_6 ) ;
return - V_60 ;
}
V_36 = F_42 ( sizeof( struct V_7 ) , V_61 ) ;
if ( ! V_36 ) {
F_28 ( L_7 ) ;
return - V_62 ;
}
if ( V_57 && ( V_55 = F_43 ( V_63 , V_53 -> V_58 . V_59 ) ) ) {
F_41 = V_55 -> V_64 ;
V_39 = F_41 ( V_36 ) ;
} else {
V_39 = F_24 ( V_36 ) ;
}
if ( V_39 ) {
F_28 ( L_8 ) ;
goto V_65;
}
V_1 = V_36 ;
V_1 -> V_13 = V_53 ;
F_18 ( V_1 ) ;
V_39 = F_44 ( V_1 , V_66 ) ;
if ( ! V_39 )
return 0 ;
V_65:
F_28 ( L_9 ) ;
F_45 ( V_36 ) ;
return V_39 ;
}
static int T_2 F_46 ( void )
{
int V_17 ;
V_17 = F_47 ( & V_67 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_48 ( & V_68 ) ;
if ( V_17 )
F_49 ( & V_67 ) ;
return V_17 ;
}
