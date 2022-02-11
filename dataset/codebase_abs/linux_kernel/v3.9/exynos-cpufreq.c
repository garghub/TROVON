static int F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 ,
V_3 -> V_4 ) ;
}
static unsigned int F_3 ( unsigned int V_5 )
{
return F_4 ( V_3 -> V_6 ) / 1000 ;
}
static int F_5 ( unsigned int V_7 )
{
struct V_8 * V_4 = V_3 -> V_4 ;
int V_9 ;
for ( V_9 = 0 ;
V_4 [ V_9 ] . V_10 != V_11 ; V_9 ++ )
if ( V_4 [ V_9 ] . V_10 == V_7 )
break;
if ( V_4 [ V_9 ] . V_10 == V_11 )
return - V_12 ;
return V_9 ;
}
static int F_6 ( unsigned int V_13 )
{
struct V_8 * V_4 = V_3 -> V_4 ;
unsigned int * V_14 = V_3 -> V_14 ;
struct V_1 * V_2 = F_7 ( 0 ) ;
unsigned int V_15 , V_16 = 0 ;
unsigned int V_17 = V_3 -> V_17 ;
int V_9 , V_18 ;
int V_19 = 0 ;
V_20 . V_21 = V_2 -> V_22 ;
V_20 . V_23 = V_13 ;
V_20 . V_5 = V_2 -> V_5 ;
if ( V_20 . V_23 == V_20 . V_21 )
goto V_24;
V_18 = F_5 ( V_20 . V_21 ) ;
if ( V_18 < 0 ) {
V_19 = V_18 ;
goto V_24;
}
V_9 = F_5 ( V_13 ) ;
if ( V_9 < 0 ) {
V_19 = V_9 ;
goto V_24;
}
if ( V_3 -> V_25 != NULL ) {
if ( V_3 -> V_25 ( V_18 , V_9 ) &&
( V_4 [ V_9 ] . V_10 < V_17 ) &&
( V_4 [ V_18 ] . V_10 < V_17 ) )
V_16 = V_14 [ V_3 -> V_26 ] ;
}
V_15 = V_14 [ V_9 ] ;
F_8 (freqs.cpu, policy->cpus)
F_9 ( & V_20 , V_27 ) ;
if ( ( V_20 . V_23 > V_20 . V_21 ) && ! V_16 ) {
V_19 = F_10 ( V_28 , V_15 , V_15 ) ;
if ( V_19 ) {
F_11 ( L_1 ,
V_29 , V_15 ) ;
goto V_24;
}
}
if ( V_16 ) {
V_19 = F_10 ( V_28 , V_16 ,
V_16 ) ;
if ( V_19 ) {
F_11 ( L_1 ,
V_29 , V_16 ) ;
goto V_24;
}
}
V_3 -> V_30 ( V_18 , V_9 ) ;
F_8 (freqs.cpu, policy->cpus)
F_9 ( & V_20 , V_31 ) ;
if ( ( V_20 . V_23 < V_20 . V_21 ) ||
( ( V_20 . V_23 > V_20 . V_21 ) && V_16 ) ) {
F_10 ( V_28 , V_15 ,
V_15 ) ;
if ( V_19 ) {
F_11 ( L_1 ,
V_29 , V_15 ) ;
goto V_24;
}
}
V_24:
F_12 ( V_2 ) ;
return V_19 ;
}
static int F_13 ( struct V_1 * V_2 ,
unsigned int V_13 ,
unsigned int V_32 )
{
struct V_8 * V_4 = V_3 -> V_4 ;
unsigned int V_9 ;
unsigned int V_33 ;
int V_19 = 0 ;
F_14 ( & V_34 ) ;
if ( V_35 )
goto V_24;
if ( F_15 ( V_2 , V_4 ,
V_13 , V_32 , & V_9 ) ) {
V_19 = - V_12 ;
goto V_24;
}
V_33 = V_4 [ V_9 ] . V_10 ;
V_19 = F_6 ( V_33 ) ;
V_24:
F_16 ( & V_34 ) ;
return V_19 ;
}
static int F_17 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_18 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_19 ( struct V_36 * V_37 ,
unsigned long V_38 , void * V_39 )
{
int V_19 ;
switch ( V_38 ) {
case V_40 :
F_14 ( & V_34 ) ;
V_35 = true ;
F_16 ( & V_34 ) ;
V_19 = F_6 ( V_41 ) ;
if ( V_19 < 0 )
return V_42 ;
break;
case V_43 :
F_14 ( & V_34 ) ;
V_35 = false ;
F_16 ( & V_34 ) ;
break;
}
return V_44 ;
}
static int F_20 ( struct V_1 * V_2 )
{
V_2 -> V_22 = V_2 -> V_45 = V_2 -> V_46 = F_3 ( V_2 -> V_5 ) ;
F_21 ( V_3 -> V_4 , V_2 -> V_5 ) ;
V_2 -> V_47 . V_48 = 100000 ;
F_22 ( V_2 -> V_49 ) ;
return F_23 ( V_2 , V_3 -> V_4 ) ;
}
static int F_24 ( struct V_1 * V_2 )
{
F_25 ( V_2 -> V_5 ) ;
return 0 ;
}
static int T_1 F_26 ( void )
{
int V_19 = - V_12 ;
V_3 = F_27 ( sizeof( struct V_50 ) , V_51 ) ;
if ( ! V_3 )
return - V_52 ;
if ( F_28 () )
V_19 = F_29 ( V_3 ) ;
else if ( F_30 () || F_31 () )
V_19 = F_32 ( V_3 ) ;
else if ( F_33 () )
V_19 = F_34 ( V_3 ) ;
else
F_11 ( L_2 , V_29 ) ;
if ( V_19 )
goto V_53;
if ( V_3 -> V_30 == NULL ) {
F_11 ( L_3 , V_29 ) ;
goto V_53;
}
V_28 = F_35 ( NULL , L_4 ) ;
if ( F_36 ( V_28 ) ) {
F_11 ( L_5 , V_29 ) ;
goto V_53;
}
V_41 = F_3 ( 0 ) ;
F_37 ( & V_54 ) ;
if ( F_38 ( & V_55 ) ) {
F_11 ( L_6 , V_29 ) ;
goto V_56;
}
return 0 ;
V_56:
F_39 ( & V_54 ) ;
F_40 ( V_28 ) ;
V_53:
F_41 ( V_3 ) ;
F_42 ( L_7 , V_29 ) ;
return - V_12 ;
}
