static char * F_1 ( void )
{
static char V_1 [ 40 ] ;
char * V_2 ;
struct V_3 * V_4 ;
memset ( V_1 , 0 , sizeof( V_1 ) ) ;
V_2 = V_1 ;
V_4 = V_5 . V_6 ;
while ( V_4 -> V_7 != V_8 ) {
if ( V_4 -> V_7 != V_9 && V_4 -> V_7 != V_10
&& V_4 -> V_7 != V_11 )
V_2 = V_2 + sprintf ( V_2 , V_4 -> V_12 . V_13 . V_14 ,
V_4 -> V_12 . V_13 . V_15 ) ;
V_4 ++ ;
}
V_2 = V_2 + sprintf ( V_2 , L_1 ) ;
return V_1 ;
}
static int F_2 ( struct V_16 * V_16 , struct V_17 * V_18 )
{
unsigned long V_19 ;
F_3 ( V_19 ) ;
if ( V_5 . V_20 ) {
F_4 ( V_19 ) ;
return - V_21 ;
}
V_5 . V_20 = 1 ;
F_4 ( V_19 ) ;
return 0 ;
}
static int F_5 ( struct V_16 * V_16 , struct V_17 * V_18 )
{
unsigned long V_19 ;
F_3 ( V_19 ) ;
V_5 . V_20 = 0 ;
V_22 = 0 ;
F_4 ( V_19 ) ;
F_6 () ;
return 0 ;
}
static T_1 F_7 ( struct V_17 * V_18 , char * V_1 , T_2 V_23 ,
T_3 * V_24 )
{
int V_25 = 0 ;
char * V_2 ;
char * V_26 ;
char V_27 ;
int V_28 ;
unsigned long V_19 ;
F_8 ( V_29 ) ;
F_3 ( V_19 ) ;
while ( 1 ) {
F_9 ( & V_30 , & V_29 , V_31 ) ;
if ( ! F_10 () || V_32 . V_33 )
break;
F_4 ( V_19 ) ;
if ( V_18 -> V_34 & V_35 ) {
F_11 ( & V_30 , & V_29 ) ;
return - V_36 ;
}
if ( F_12 ( V_37 ) ) {
F_11 ( & V_30 , & V_29 ) ;
return - V_38 ;
}
F_13 () ;
F_3 ( V_19 ) ;
}
F_11 ( & V_30 , & V_29 ) ;
V_2 = V_1 ;
V_26 = F_1 () ;
while ( V_25 < V_23 ) {
if ( V_32 . V_33 ) {
V_32 . V_33 = 0 ;
V_27 = '\x18' ;
} else if ( F_10 () ) {
break;
} else if ( ! V_22 ) {
if ( * V_26 ) {
V_27 = * V_26 ;
V_26 ++ ;
} else {
V_22 = 1 ;
}
} else {
V_27 = F_14 () ;
}
F_4 ( V_19 ) ;
if ( F_15 ( V_2 , & V_27 , 1 ) )
return - V_39 ;
F_3 ( V_19 ) ;
V_25 ++ ;
V_2 ++ ;
}
* V_24 += V_25 ;
V_28 = F_10 () ;
F_4 ( V_19 ) ;
if ( V_28 ) {
F_6 () ;
* V_24 = 0 ;
}
return V_25 ;
}
static T_1 F_16 ( struct V_17 * V_18 , const char * V_1 , T_2 V_23 ,
T_3 * V_24 )
{
unsigned long V_40 = 0 ;
int V_41 ;
V_41 = F_17 ( V_1 , V_23 , 0 , & V_40 ) ;
if ( V_41 < 0 )
return V_41 ;
V_42 = V_40 ;
return V_23 ;
}
static unsigned int F_18 ( struct V_17 * V_18 ,
struct V_43 * V_29 )
{
unsigned long V_19 ;
int V_44 = 0 ;
F_19 ( V_18 , & V_30 , V_29 ) ;
F_3 ( V_19 ) ;
if ( ! F_10 () || V_32 . V_33 )
V_44 = V_45 | V_46 ;
F_4 ( V_19 ) ;
return V_44 ;
}
static unsigned char F_20 ( void )
{
int V_47 ;
V_47 = V_42 ;
V_42 = 0 ;
return V_47 ;
}
static int F_21 ( struct V_48 * V_49 )
{
if ( V_50 != 0 )
return 0 ;
memset ( & V_51 , 0 , sizeof( V_51 ) ) ;
V_51 . V_52 = V_53 ;
V_51 . V_54 = L_2 ;
V_51 . V_55 = & V_56 ;
if ( F_22 ( & V_51 ) ) {
F_23 ( L_3 ) ;
return - V_57 ;
}
V_50 = 1 ;
F_24 ( L_4 ) ;
return 0 ;
}
static void F_25 ( void )
{
F_26 ( & V_51 ) ;
V_50 = 0 ;
F_24 ( L_5 ) ;
}
static int F_27 ( struct V_48 * V_49 )
{
if ( V_5 . V_20 )
return 1 ;
return 0 ;
}
static int T_4 F_28 ( void )
{
return F_29 ( & V_5 ) ;
}
static void T_5 F_30 ( void )
{
F_31 ( & V_5 ) ;
}
