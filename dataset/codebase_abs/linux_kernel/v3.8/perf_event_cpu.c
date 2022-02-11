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
return & F_4 ( V_6 ) ;
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
static void F_18 ( struct V_7 * V_1 )
{
int V_20 ;
F_19 (cpu) {
struct V_5 * V_21 = & F_20 ( V_6 , V_20 ) ;
V_21 -> V_21 = F_20 ( V_22 , V_20 ) ;
V_21 -> V_23 = F_20 ( V_23 , V_20 ) ;
F_21 ( & V_21 -> V_24 ) ;
}
V_1 -> V_25 = F_3 ;
V_1 -> F_16 = F_11 ;
V_1 -> F_10 = F_5 ;
if ( V_1 && V_1 -> V_26 )
F_22 ( V_1 -> V_26 , V_1 , 1 ) ;
}
static int T_2 F_23 ( struct V_27 * V_28 ,
unsigned long V_29 , void * V_30 )
{
if ( ( V_29 & ~ V_31 ) != V_32 )
return V_33 ;
if ( V_1 && V_1 -> V_26 )
V_1 -> V_26 ( V_1 ) ;
else
return V_33 ;
return V_34 ;
}
static int F_24 ( struct V_7 * V_35 )
{
int V_20 = F_25 () ;
unsigned long V_36 = F_26 () ;
unsigned long V_37 = ( V_36 & 0xFF000000 ) >> 24 ;
unsigned long V_38 = ( V_36 & 0xFFF0 ) ;
int V_39 = - V_18 ;
F_27 ( L_5 , V_20 ) ;
if ( 0x41 == V_37 ) {
switch ( V_38 ) {
case 0xB360 :
case 0xB560 :
case 0xB760 :
V_39 = F_28 ( V_35 ) ;
break;
case 0xB020 :
V_39 = F_29 ( V_35 ) ;
break;
case 0xC080 :
V_39 = F_30 ( V_35 ) ;
break;
case 0xC090 :
V_39 = F_31 ( V_35 ) ;
break;
case 0xC050 :
V_39 = F_32 ( V_35 ) ;
break;
case 0xC0F0 :
V_39 = F_33 ( V_35 ) ;
break;
case 0xC070 :
V_39 = F_34 ( V_35 ) ;
break;
}
} else if ( 0x69 == V_37 ) {
V_38 = ( V_36 >> 13 ) & 0x7 ;
switch ( V_38 ) {
case 1 :
V_39 = F_35 ( V_35 ) ;
break;
case 2 :
V_39 = F_36 ( V_35 ) ;
break;
}
}
F_37 () ;
return V_39 ;
}
static int F_38 ( struct V_11 * V_40 )
{
const struct V_41 * V_42 ;
int (* F_39)( struct V_7 * );
struct V_43 * V_44 = V_40 -> V_45 . V_46 ;
struct V_7 * V_35 ;
int V_39 = - V_18 ;
if ( V_1 ) {
F_27 ( L_6 ) ;
return - V_47 ;
}
V_35 = F_40 ( sizeof( struct V_7 ) , V_48 ) ;
if ( ! V_35 ) {
F_27 ( L_7 ) ;
return - V_49 ;
}
if ( V_44 && ( V_42 = F_41 ( V_50 , V_40 -> V_45 . V_46 ) ) ) {
F_39 = V_42 -> V_51 ;
V_39 = F_39 ( V_35 ) ;
} else {
V_39 = F_24 ( V_35 ) ;
}
if ( V_39 ) {
F_27 ( L_8 ) ;
F_42 ( V_35 ) ;
return V_39 ;
}
V_1 = V_35 ;
V_1 -> V_13 = V_40 ;
F_18 ( V_1 ) ;
F_43 ( V_1 , V_52 ) ;
return 0 ;
}
static int T_3 F_44 ( void )
{
int V_17 ;
V_17 = F_45 ( & V_53 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_46 ( & V_54 ) ;
if ( V_17 )
F_47 ( & V_53 ) ;
return V_17 ;
}
