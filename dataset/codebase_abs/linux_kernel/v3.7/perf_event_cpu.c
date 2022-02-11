const char * F_1 ( void )
{
if ( ! V_1 )
return NULL ;
return V_1 -> V_2 . V_3 ;
}
int F_2 ( void )
{
int V_4 = 0 ;
if ( V_1 != NULL )
V_4 = V_1 -> V_5 ;
return V_4 ;
}
static struct V_6 * F_3 ( void )
{
return & F_4 ( V_7 ) ;
}
static void F_5 ( void )
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
static int F_11 ( T_1 V_16 )
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
V_17 = F_16 ( V_9 , V_16 , V_19 , L_3 ,
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
static void T_2 F_18 ( struct V_20 * V_1 )
{
int V_21 ;
F_19 (cpu) {
struct V_6 * V_22 = & F_20 ( V_7 , V_21 ) ;
V_22 -> V_22 = F_20 ( V_23 , V_21 ) ;
V_22 -> V_24 = F_20 ( V_24 , V_21 ) ;
F_21 ( & V_22 -> V_25 ) ;
}
V_1 -> V_26 = F_3 ;
V_1 -> F_16 = F_11 ;
V_1 -> F_10 = F_5 ;
if ( V_1 && V_1 -> V_27 )
F_22 ( V_1 -> V_27 , NULL , 1 ) ;
}
static int T_3 F_23 ( struct V_28 * V_29 ,
unsigned long V_30 , void * V_31 )
{
if ( ( V_30 & ~ V_32 ) != V_33 )
return V_34 ;
if ( V_1 && V_1 -> V_27 )
V_1 -> V_27 ( NULL ) ;
return V_35 ;
}
static struct V_20 * T_2 F_24 ( void )
{
struct V_20 * V_2 = NULL ;
int V_21 = F_25 () ;
unsigned long V_36 = F_26 () ;
unsigned long V_37 = ( V_36 & 0xFF000000 ) >> 24 ;
unsigned long V_38 = ( V_36 & 0xFFF0 ) ;
F_27 ( L_5 , V_21 ) ;
if ( 0x41 == V_37 ) {
switch ( V_38 ) {
case 0xB360 :
case 0xB560 :
case 0xB760 :
V_2 = F_28 () ;
break;
case 0xB020 :
V_2 = F_29 () ;
break;
case 0xC080 :
V_2 = F_30 () ;
break;
case 0xC090 :
V_2 = F_31 () ;
break;
case 0xC050 :
V_2 = F_32 () ;
break;
case 0xC0F0 :
V_2 = F_33 () ;
break;
case 0xC070 :
V_2 = F_34 () ;
break;
}
} else if ( 0x69 == V_37 ) {
V_38 = ( V_36 >> 13 ) & 0x7 ;
switch ( V_38 ) {
case 1 :
V_2 = F_35 () ;
break;
case 2 :
V_2 = F_36 () ;
break;
}
}
F_37 () ;
return V_2 ;
}
static int T_2 F_38 ( struct V_11 * V_39 )
{
const struct V_40 * V_41 ;
struct V_20 * ( * V_42 ) ( void ) ;
struct V_43 * V_44 = V_39 -> V_45 . V_46 ;
if ( V_1 ) {
F_27 ( L_6 ) ;
return - V_47 ;
}
if ( V_44 && ( V_41 = F_39 ( V_48 , V_39 -> V_45 . V_46 ) ) ) {
V_42 = V_41 -> V_49 ;
V_1 = V_42 () ;
} else {
V_1 = F_24 () ;
}
if ( ! V_1 )
return - V_18 ;
V_1 -> V_13 = V_39 ;
F_18 ( V_1 ) ;
F_40 ( & V_50 ) ;
F_41 ( V_1 , V_1 -> V_3 , V_51 ) ;
return 0 ;
}
static int T_4 F_42 ( void )
{
return F_43 ( & V_52 ) ;
}
