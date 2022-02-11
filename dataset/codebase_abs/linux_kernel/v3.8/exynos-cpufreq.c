static int F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 ,
V_3 -> V_4 ) ;
}
static unsigned int F_3 ( unsigned int V_5 )
{
return F_4 ( V_3 -> V_6 ) / 1000 ;
}
static int F_5 ( struct V_1 * V_2 ,
unsigned int V_7 ,
unsigned int V_8 )
{
unsigned int V_9 , V_10 ;
unsigned int V_11 , V_12 = 0 ;
int V_13 = 0 ;
struct V_14 * V_4 = V_3 -> V_4 ;
unsigned int * V_15 = V_3 -> V_15 ;
unsigned int V_16 = V_3 -> V_16 ;
F_6 ( & V_17 ) ;
V_18 . V_19 = V_2 -> V_20 ;
if ( V_21 && V_7 != V_22 ) {
V_13 = - V_23 ;
goto V_24;
}
for ( V_10 = 0 ;
V_4 [ V_10 ] . V_25 != V_26 ;
V_10 ++ )
if ( V_4 [ V_10 ] . V_25 == V_18 . V_19 )
break;
if ( V_4 [ V_10 ] . V_25 == V_26 ) {
V_13 = - V_27 ;
goto V_24;
}
if ( F_7 ( V_2 , V_4 ,
V_7 , V_8 , & V_9 ) ) {
V_13 = - V_27 ;
goto V_24;
}
V_18 . V_28 = V_4 [ V_9 ] . V_25 ;
V_18 . V_5 = V_2 -> V_5 ;
if ( V_3 -> V_29 != NULL ) {
if ( V_3 -> V_29 ( V_10 , V_9 ) &&
( V_4 [ V_9 ] . V_25 < V_16 ) &&
( V_4 [ V_10 ] . V_25 < V_16 ) )
V_12 = V_15 [ V_3 -> V_30 ] ;
}
V_11 = V_15 [ V_9 ] ;
F_8 (freqs.cpu, policy->cpus)
F_9 ( & V_18 , V_31 ) ;
if ( ( V_18 . V_28 > V_18 . V_19 ) && ! V_12 ) {
F_10 ( V_32 , V_11 ,
V_11 ) ;
}
if ( V_12 )
F_10 ( V_32 , V_12 ,
V_12 ) ;
if ( V_18 . V_28 != V_18 . V_19 )
V_3 -> V_33 ( V_10 , V_9 ) ;
F_8 (freqs.cpu, policy->cpus)
F_9 ( & V_18 , V_34 ) ;
if ( ( V_18 . V_28 < V_18 . V_19 ) ||
( ( V_18 . V_28 > V_18 . V_19 ) && V_12 ) ) {
F_10 ( V_32 , V_11 ,
V_11 ) ;
}
V_24:
F_11 ( & V_17 ) ;
return V_13 ;
}
static int F_12 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_14 ( struct V_35 * V_36 ,
unsigned long V_37 , void * V_38 )
{
struct V_1 * V_2 = F_15 ( 0 ) ;
static unsigned int V_39 ;
unsigned int V_40 ;
F_6 ( & V_17 ) ;
switch ( V_37 ) {
case V_41 :
if ( V_21 )
goto V_24;
V_21 = true ;
if ( V_22 ) {
V_39 = F_3 ( 0 ) ;
F_11 ( & V_17 ) ;
F_5 ( V_2 , V_22 ,
V_42 ) ;
F_6 ( & V_17 ) ;
}
break;
case V_43 :
if ( V_39 ) {
V_40 = V_22 ;
V_22 = V_39 ;
F_11 ( & V_17 ) ;
F_5 ( V_2 , V_22 ,
V_42 ) ;
F_6 ( & V_17 ) ;
V_22 = V_40 ;
}
V_21 = false ;
break;
}
V_24:
F_11 ( & V_17 ) ;
return V_44 ;
}
static int F_16 ( struct V_1 * V_2 )
{
V_2 -> V_20 = V_2 -> V_45 = V_2 -> V_46 = F_3 ( V_2 -> V_5 ) ;
F_17 ( V_3 -> V_4 , V_2 -> V_5 ) ;
V_22 = F_3 ( 0 ) ;
V_2 -> V_47 . V_48 = 100000 ;
if ( F_18 () == 1 ) {
F_19 ( V_2 -> V_49 , V_50 ) ;
F_19 ( V_2 -> V_51 , V_52 ) ;
} else {
V_2 -> V_53 = V_54 ;
F_20 ( V_2 -> V_51 ) ;
}
return F_21 ( V_2 , V_3 -> V_4 ) ;
}
static int T_1 F_22 ( void )
{
int V_13 = - V_27 ;
V_3 = F_23 ( sizeof( struct V_55 ) , V_56 ) ;
if ( ! V_3 )
return - V_57 ;
if ( F_24 () )
V_13 = F_25 ( V_3 ) ;
else if ( F_26 () || F_27 () )
V_13 = F_28 ( V_3 ) ;
else if ( F_29 () )
V_13 = F_30 ( V_3 ) ;
else
F_31 ( L_1 , V_58 ) ;
if ( V_13 )
goto V_59;
if ( V_3 -> V_33 == NULL ) {
F_31 ( L_2 , V_58 ) ;
goto V_59;
}
V_32 = F_32 ( NULL , L_3 ) ;
if ( F_33 ( V_32 ) ) {
F_31 ( L_4 , V_58 ) ;
goto V_59;
}
F_34 ( & V_60 ) ;
if ( F_35 ( & V_61 ) ) {
F_31 ( L_5 , V_58 ) ;
goto V_62;
}
return 0 ;
V_62:
F_36 ( & V_60 ) ;
if ( ! F_33 ( V_32 ) )
F_37 ( V_32 ) ;
V_59:
F_38 ( V_3 ) ;
F_39 ( L_6 , V_58 ) ;
return - V_27 ;
}
