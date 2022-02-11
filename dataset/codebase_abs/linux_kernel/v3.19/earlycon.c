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
static int T_2 F_7 ( struct V_7 * V_8 ,
char * V_9 )
{
struct V_10 * V_11 = & V_8 -> V_11 ;
int V_12 , V_13 , V_14 ;
unsigned long V_15 ;
if ( ! V_9 )
return - V_16 ;
V_12 = ! strncmp ( V_9 , L_2 , 5 ) ;
V_13 = ! strncmp ( V_9 , L_3 , 7 ) ;
if ( V_12 || V_13 ) {
V_11 -> V_17 = ( V_12 ? V_18 : V_19 ) ;
V_9 += V_12 ? 5 : 7 ;
V_15 = F_8 ( V_9 , NULL , 0 ) ;
V_11 -> V_20 = V_15 ;
if ( V_13 )
V_11 -> V_21 = 2 ;
} else if ( ! strncmp ( V_9 , L_4 , 3 ) ) {
V_11 -> V_17 = V_22 ;
V_9 += 3 ;
V_15 = F_8 ( V_9 , NULL , 0 ) ;
V_11 -> V_23 = V_15 ;
V_12 = 0 ;
} else if ( ! strncmp ( V_9 , L_5 , 2 ) ) {
V_11 -> V_17 = V_18 ;
V_15 = F_8 ( V_9 , NULL , 0 ) ;
V_11 -> V_20 = V_15 ;
} else {
return - V_24 ;
}
V_11 -> V_25 = V_26 * 16 ;
V_9 = strchr ( V_9 , ',' ) ;
if ( V_9 ) {
V_9 ++ ;
V_8 -> V_27 = F_8 ( V_9 , NULL , 0 ) ;
V_14 = F_9 ( strcspn ( V_9 , L_6 ) + 1 ,
( T_3 ) ( sizeof( V_8 -> V_9 ) ) ) ;
F_10 ( V_8 -> V_9 , V_9 , V_14 ) ;
}
if ( V_11 -> V_17 == V_18 || V_11 -> V_17 == V_19 )
F_11 ( L_7 ,
V_13 ? L_8 : L_9 ,
( unsigned long long ) V_11 -> V_20 ,
V_8 -> V_9 ) ;
else
F_11 ( L_10 ,
V_11 -> V_23 ,
V_8 -> V_9 ) ;
return 0 ;
}
int T_2 F_12 ( char * V_28 , const char * V_29 ,
int (* F_13)( struct V_7 * , const char * ) )
{
int V_30 ;
T_3 V_31 ;
struct V_10 * V_11 = & V_32 . V_11 ;
if ( ! V_28 || ! V_29 || ! F_13 )
return 0 ;
V_31 = strlen ( V_29 ) ;
if ( strncmp ( V_28 , V_29 , V_31 ) )
return 0 ;
if ( V_28 [ V_31 ] && ( V_28 [ V_31 ] != ',' ) )
return 0 ;
V_28 += V_31 + 1 ;
V_30 = F_7 ( & V_32 , V_28 ) ;
if ( ! V_30 )
V_28 = NULL ;
if ( V_11 -> V_20 )
V_11 -> V_33 = F_1 ( V_11 -> V_20 , 64 ) ;
V_32 . V_34 -> V_35 = & V_32 ;
V_30 = F_13 ( & V_32 , V_28 ) ;
if ( V_30 < 0 )
return V_30 ;
if ( ! V_32 . V_34 -> V_36 )
return - V_16 ;
F_14 ( V_32 . V_34 ) ;
return 0 ;
}
int T_2 F_15 ( unsigned long V_15 ,
int (* F_13)( struct V_7 * , const char * ) )
{
int V_30 ;
struct V_10 * V_11 = & V_32 . V_11 ;
V_11 -> V_17 = V_18 ;
V_11 -> V_20 = V_15 ;
V_11 -> V_25 = V_26 * 16 ;
V_11 -> V_33 = F_1 ( V_15 , V_37 ) ;
V_32 . V_34 -> V_35 = & V_32 ;
V_30 = F_13 ( & V_32 , NULL ) ;
if ( V_30 < 0 )
return V_30 ;
if ( ! V_32 . V_34 -> V_36 )
return - V_16 ;
F_14 ( V_32 . V_34 ) ;
return 0 ;
}
