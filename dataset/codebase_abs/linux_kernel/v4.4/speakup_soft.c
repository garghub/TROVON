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
F_3 ( & V_20 . V_21 , V_19 ) ;
if ( V_5 . V_22 ) {
F_4 ( & V_20 . V_21 , V_19 ) ;
return - V_23 ;
}
V_5 . V_22 = 1 ;
F_4 ( & V_20 . V_21 , V_19 ) ;
return 0 ;
}
static int F_5 ( struct V_16 * V_16 , struct V_17 * V_18 )
{
unsigned long V_19 ;
F_3 ( & V_20 . V_21 , V_19 ) ;
V_5 . V_22 = 0 ;
V_24 = 0 ;
F_4 ( & V_20 . V_21 , V_19 ) ;
F_6 () ;
return 0 ;
}
static T_1 F_7 ( struct V_17 * V_18 , char T_2 * V_1 , T_3 V_25 ,
T_4 * V_26 )
{
int V_27 = 0 ;
char T_2 * V_2 ;
char * V_28 ;
char V_29 ;
int V_30 ;
unsigned long V_19 ;
F_8 ( V_31 ) ;
F_3 ( & V_20 . V_21 , V_19 ) ;
while ( 1 ) {
F_9 ( & V_32 , & V_31 , V_33 ) ;
if ( ! F_10 () || V_20 . V_34 )
break;
F_4 ( & V_20 . V_21 , V_19 ) ;
if ( V_18 -> V_35 & V_36 ) {
F_11 ( & V_32 , & V_31 ) ;
return - V_37 ;
}
if ( F_12 ( V_38 ) ) {
F_11 ( & V_32 , & V_31 ) ;
return - V_39 ;
}
F_13 () ;
F_3 ( & V_20 . V_21 , V_19 ) ;
}
F_11 ( & V_32 , & V_31 ) ;
V_2 = V_1 ;
V_28 = F_1 () ;
while ( V_27 < V_25 ) {
if ( V_20 . V_34 ) {
V_20 . V_34 = 0 ;
V_29 = '\x18' ;
} else if ( F_10 () ) {
break;
} else if ( V_28 [ V_24 ] ) {
V_29 = V_28 [ V_24 ++ ] ;
} else {
V_29 = F_14 () ;
}
F_4 ( & V_20 . V_21 , V_19 ) ;
if ( F_15 ( V_2 , & V_29 , 1 ) )
return - V_40 ;
F_3 ( & V_20 . V_21 , V_19 ) ;
V_27 ++ ;
V_2 ++ ;
}
* V_26 += V_27 ;
V_30 = F_10 () ;
F_4 ( & V_20 . V_21 , V_19 ) ;
if ( V_30 ) {
F_6 () ;
* V_26 = 0 ;
}
return V_27 ;
}
static T_1 F_16 ( struct V_17 * V_18 , const char T_2 * V_1 ,
T_3 V_25 , T_4 * V_26 )
{
unsigned long V_41 = 0 ;
int V_42 ;
V_42 = F_17 ( V_1 , V_25 , 0 , & V_41 ) ;
if ( V_42 < 0 )
return V_42 ;
V_43 = V_41 ;
return V_25 ;
}
static unsigned int F_18 ( struct V_17 * V_18 ,
struct V_44 * V_31 )
{
unsigned long V_19 ;
int V_45 = 0 ;
F_19 ( V_18 , & V_32 , V_31 ) ;
F_3 ( & V_20 . V_21 , V_19 ) ;
if ( ! F_10 () || V_20 . V_34 )
V_45 = V_46 | V_47 ;
F_4 ( & V_20 . V_21 , V_19 ) ;
return V_45 ;
}
static unsigned char F_20 ( void )
{
int V_48 ;
V_48 = V_43 ;
V_43 = 0 ;
return V_48 ;
}
static int F_21 ( struct V_49 * V_50 )
{
if ( V_51 != 0 )
return 0 ;
memset ( & V_52 , 0 , sizeof( V_52 ) ) ;
V_52 . V_53 = V_54 ;
V_52 . V_55 = L_2 ;
V_52 . V_56 = & V_57 ;
if ( F_22 ( & V_52 ) ) {
F_23 ( L_3 ) ;
return - V_58 ;
}
V_51 = 1 ;
F_24 ( L_4 ) ;
return 0 ;
}
static void F_25 ( void )
{
F_26 ( & V_52 ) ;
V_51 = 0 ;
F_24 ( L_5 ) ;
}
static int F_27 ( struct V_49 * V_50 )
{
if ( V_5 . V_22 )
return 1 ;
return 0 ;
}
