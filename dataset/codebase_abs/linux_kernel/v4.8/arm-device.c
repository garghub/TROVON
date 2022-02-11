static int F_1 ( const struct V_1 * V_2 ,
unsigned int V_3 )
{
unsigned int V_4 , V_5 , V_6 ;
int V_7 = 0 ;
const struct V_1 * V_8 ;
struct V_9 V_10 ;
for ( V_4 = 0 ; V_4 < V_3 ; V_4 ++ ) {
V_8 = & V_2 [ V_4 ] ;
V_6 = F_2 ( F_3 ( V_8 ) , V_11 ) ;
if ( ( F_4 ( V_8 ) != V_12 ) || ( V_6 == 0 ) )
continue;
for ( V_5 = 0 ; V_5 < V_6 ; V_5 ++ ) {
V_10 . V_13 = V_14 ;
V_10 . V_15 = F_5 ( V_8 -> V_16 ) + V_5 ;
V_7 = F_6 ( V_17 ,
& V_10 ) ;
if ( V_7 )
return V_7 ;
}
}
return V_7 ;
}
static int F_7 ( const struct V_1 * V_2 ,
unsigned int V_3 )
{
unsigned int V_4 , V_5 , V_6 ;
int V_7 = 0 ;
const struct V_1 * V_8 ;
T_1 * V_18 ;
T_2 * V_19 ;
int * V_20 ;
struct V_21 V_22 ;
for ( V_4 = 0 ; V_4 < V_3 ; V_4 ++ ) {
V_8 = & V_2 [ V_4 ] ;
V_6 = F_2 ( F_3 ( V_8 ) , V_11 ) ;
if ( ( F_4 ( V_8 ) != V_12 ) || ( V_6 == 0 ) )
continue;
V_18 = F_8 ( sizeof( T_1 ) * V_6 , V_23 ) ;
V_19 = F_8 ( sizeof( T_2 ) * V_6 , V_23 ) ;
V_20 = F_8 ( sizeof( int ) * V_6 , V_23 ) ;
if ( ! V_18 || ! V_19 || ! V_20 ) {
F_9 ( V_18 ) ;
F_9 ( V_19 ) ;
F_9 ( V_20 ) ;
V_7 = - V_24 ;
goto V_25;
}
for ( V_5 = 0 ; V_5 < V_6 ; V_5 ++ ) {
V_18 [ V_5 ] = F_5 ( V_8 -> V_16 ) + V_5 ;
V_19 [ V_5 ] = F_5 ( V_8 -> V_16 ) + V_5 ;
}
V_22 . V_13 = V_14 ;
V_22 . V_26 = V_6 ;
V_22 . V_27 = V_28 ;
F_10 ( V_22 . V_18 , V_18 ) ;
F_10 ( V_22 . V_19 , V_19 ) ;
F_10 ( V_22 . V_20 , V_20 ) ;
V_7 = F_6 ( V_29 , & V_22 ) ;
F_9 ( V_18 ) ;
F_9 ( V_19 ) ;
F_9 ( V_20 ) ;
if ( V_7 )
goto V_25;
}
return V_7 ;
V_25:
F_1 ( V_2 , V_4 ) ;
return V_7 ;
}
static int F_11 ( struct V_30 * V_31 ,
unsigned long V_32 , void * V_33 )
{
struct V_34 * V_35 = F_12 ( V_33 ) ;
int V_8 = 0 ;
if ( V_35 -> V_36 == 0 || V_35 -> V_1 == NULL )
return V_37 ;
switch ( V_32 ) {
case V_38 :
V_8 = F_7 ( V_35 -> V_1 , V_35 -> V_36 ) ;
break;
case V_39 :
V_8 = F_1 ( V_35 -> V_1 , V_35 -> V_36 ) ;
break;
default:
return V_40 ;
}
if ( V_8 )
F_13 ( & V_35 -> V_41 , L_1 ,
V_32 == V_38 ? L_2 :
( V_32 == V_39 ? L_3 : L_4 ) ,
V_35 -> V_42 ) ;
return V_37 ;
}
static int T_3 F_14 ( void )
{
if ( ! F_15 () || V_43 )
return 0 ;
return F_16 ( & V_44 , & V_45 ) ;
}
static int F_17 ( struct V_30 * V_31 ,
unsigned long V_32 , void * V_33 )
{
struct V_46 * V_47 = F_18 ( V_33 ) ;
int V_8 = 0 ;
switch ( V_32 ) {
case V_38 :
V_8 = F_7 ( & V_47 -> V_48 , 1 ) ;
break;
case V_39 :
V_8 = F_1 ( & V_47 -> V_48 , 1 ) ;
break;
default:
return V_40 ;
}
if ( V_8 )
F_13 ( & V_47 -> V_41 , L_5 ,
V_32 == V_38 ? L_2 :
( V_32 == V_39 ? L_3 : L_4 ) ,
V_47 -> V_41 . V_49 ) ;
return V_37 ;
}
static int T_3 F_19 ( void )
{
if ( ! F_15 () || V_43 )
return 0 ;
return F_16 ( & V_50 , & V_51 ) ;
}
