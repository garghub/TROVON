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
V_11 -> V_17 = V_13 ;
break;
case V_18 :
V_11 -> V_19 = 1 ;
V_11 -> V_17 = V_13 ;
break;
case V_20 :
case V_21 :
V_11 -> V_19 = 2 ;
V_11 -> V_17 = V_13 ;
break;
case V_22 :
V_11 -> V_23 = V_13 ;
break;
default:
return - V_15 ;
}
if ( V_9 ) {
V_8 -> V_24 = F_9 ( V_9 , NULL , 0 ) ;
V_12 = F_10 ( strcspn ( V_9 , L_2 ) + 1 ,
( T_3 ) ( sizeof( V_8 -> V_9 ) ) ) ;
F_11 ( V_8 -> V_9 , V_9 , V_12 ) ;
}
if ( V_11 -> V_14 == V_16 || V_11 -> V_14 == V_18 ||
V_11 -> V_14 == V_20 || V_11 -> V_14 == V_21 )
F_12 ( L_3 ,
( V_11 -> V_14 == V_16 ) ? L_4 :
( V_11 -> V_14 == V_18 ) ? L_5 :
( V_11 -> V_14 == V_20 ) ? L_6 : L_7 ,
( unsigned long long ) V_11 -> V_17 ,
V_8 -> V_9 ) ;
else
F_12 ( L_8 ,
V_11 -> V_23 ,
V_8 -> V_9 ) ;
return 0 ;
}
static int T_2 F_13 ( char * V_25 , const struct V_26 * V_27 )
{
int V_28 ;
struct V_10 * V_11 = & V_29 . V_11 ;
if ( V_25 && ! F_7 ( & V_29 , V_25 ) )
V_25 = NULL ;
F_14 ( & V_11 -> V_30 ) ;
V_11 -> V_31 = V_32 * 16 ;
if ( V_11 -> V_17 )
V_11 -> V_33 = F_1 ( V_11 -> V_17 , 64 ) ;
V_29 . V_34 -> V_35 = & V_29 ;
V_28 = V_27 -> V_36 ( & V_29 , V_25 ) ;
if ( V_28 < 0 )
return V_28 ;
if ( ! V_29 . V_34 -> V_37 )
return - V_38 ;
F_15 ( V_29 . V_34 ) ;
return 0 ;
}
int T_2 F_16 ( char * V_25 )
{
const struct V_26 * V_27 ;
if ( ! V_25 || ! V_25 [ 0 ] )
return - V_15 ;
if ( V_39 . V_40 & V_41 )
return - V_42 ;
for ( V_27 = V_43 ; V_27 -> V_44 [ 0 ] ; V_27 ++ ) {
T_3 V_45 = strlen ( V_27 -> V_44 ) ;
if ( strncmp ( V_25 , V_27 -> V_44 , V_45 ) )
continue;
if ( V_25 [ V_45 ] ) {
if ( V_25 [ V_45 ] != ',' )
continue;
V_25 += V_45 + 1 ;
} else
V_25 = NULL ;
return F_13 ( V_25 , V_27 ) ;
}
return - V_46 ;
}
static int T_2 F_17 ( char * V_25 )
{
int V_28 ;
if ( ! V_25 || ! V_25 [ 0 ] )
return 0 ;
V_28 = F_16 ( V_25 ) ;
if ( V_28 == - V_46 || V_28 == - V_42 )
return 0 ;
return V_28 ;
}
int T_2 F_18 ( unsigned long V_13 ,
int (* V_36)( struct V_7 * , const char * ) )
{
int V_28 ;
struct V_10 * V_11 = & V_29 . V_11 ;
F_14 ( & V_11 -> V_30 ) ;
V_11 -> V_14 = V_16 ;
V_11 -> V_17 = V_13 ;
V_11 -> V_31 = V_32 * 16 ;
V_11 -> V_33 = F_1 ( V_13 , V_47 ) ;
V_29 . V_34 -> V_35 = & V_29 ;
V_28 = V_36 ( & V_29 , NULL ) ;
if ( V_28 < 0 )
return V_28 ;
if ( ! V_29 . V_34 -> V_37 )
return - V_38 ;
F_15 ( V_29 . V_34 ) ;
return 0 ;
}
