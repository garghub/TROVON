static void T_1 * T_2 F_1 ( unsigned long V_1 , T_3 V_2 )
{
void T_1 * V_3 ;
#ifdef F_2
F_3 ( V_4 , V_1 & V_5 ) ;
V_3 = ( void T_1 * ) F_4 ( V_4 ) ;
V_3 += V_1 & ~ V_5 ;
#else
V_3 = F_5 ( V_1 , V_2 ) ;
#endif
if ( ! V_3 )
F_6 ( L_1 , V_6 ,
( unsigned long long ) V_1 ) ;
return V_3 ;
}
static int T_2 F_7 ( struct V_7 * V_8 , char * V_9 )
{
struct V_10 * V_11 = & V_8 -> V_11 ;
int V_12 ;
unsigned long V_13 ;
if ( F_8 ( V_9 , & V_11 -> V_14 , & V_13 , & V_9 ) )
return - V_15 ;
switch ( V_11 -> V_14 ) {
case V_16 :
V_11 -> V_17 = 2 ;
case V_18 :
V_11 -> V_19 = V_13 ;
break;
case V_20 :
V_11 -> V_21 = V_13 ;
break;
default:
return - V_15 ;
}
if ( V_9 ) {
V_8 -> V_22 = F_9 ( V_9 , NULL , 0 ) ;
V_12 = F_10 ( strcspn ( V_9 , L_2 ) + 1 ,
( T_3 ) ( sizeof( V_8 -> V_9 ) ) ) ;
F_11 ( V_8 -> V_9 , V_9 , V_12 ) ;
}
if ( V_11 -> V_14 == V_18 || V_11 -> V_14 == V_16 )
F_12 ( L_3 ,
( V_11 -> V_14 == V_16 ) ? L_4 : L_5 ,
( unsigned long long ) V_11 -> V_19 ,
V_8 -> V_9 ) ;
else
F_12 ( L_6 ,
V_11 -> V_21 ,
V_8 -> V_9 ) ;
return 0 ;
}
static int T_2 F_13 ( char * V_23 , const struct V_24 * V_25 )
{
int V_26 ;
struct V_10 * V_11 = & V_27 . V_11 ;
if ( V_23 && ! F_7 ( & V_27 , V_23 ) )
V_23 = NULL ;
V_11 -> V_28 = V_29 * 16 ;
if ( V_11 -> V_19 )
V_11 -> V_30 = F_1 ( V_11 -> V_19 , 64 ) ;
V_27 . V_31 -> V_32 = & V_27 ;
V_26 = V_25 -> V_33 ( & V_27 , V_23 ) ;
if ( V_26 < 0 )
return V_26 ;
if ( ! V_27 . V_31 -> V_34 )
return - V_35 ;
F_14 ( V_27 . V_31 ) ;
return 0 ;
}
int T_2 F_15 ( char * V_23 )
{
const struct V_24 * V_25 ;
if ( ! V_23 || ! V_23 [ 0 ] )
return - V_15 ;
if ( V_36 . V_37 & V_38 )
return - V_39 ;
for ( V_25 = V_40 ; V_25 -> V_41 [ 0 ] ; V_25 ++ ) {
T_3 V_42 = strlen ( V_25 -> V_41 ) ;
if ( strncmp ( V_23 , V_25 -> V_41 , V_42 ) )
continue;
if ( V_23 [ V_42 ] ) {
if ( V_23 [ V_42 ] != ',' )
continue;
V_23 += V_42 + 1 ;
} else
V_23 = NULL ;
return F_13 ( V_23 , V_25 ) ;
}
return - V_43 ;
}
static int T_2 F_16 ( char * V_23 )
{
int V_26 ;
if ( ! V_23 || ! V_23 [ 0 ] )
return 0 ;
V_26 = F_15 ( V_23 ) ;
if ( V_26 == - V_43 || V_26 == - V_39 )
return 0 ;
return V_26 ;
}
int T_2 F_17 ( unsigned long V_13 ,
int (* V_33)( struct V_7 * , const char * ) )
{
int V_26 ;
struct V_10 * V_11 = & V_27 . V_11 ;
V_11 -> V_14 = V_18 ;
V_11 -> V_19 = V_13 ;
V_11 -> V_28 = V_29 * 16 ;
V_11 -> V_30 = F_1 ( V_13 , V_44 ) ;
V_27 . V_31 -> V_32 = & V_27 ;
V_26 = V_33 ( & V_27 , NULL ) ;
if ( V_26 < 0 )
return V_26 ;
if ( ! V_27 . V_31 -> V_34 )
return - V_35 ;
F_14 ( V_27 . V_31 ) ;
return 0 ;
}
