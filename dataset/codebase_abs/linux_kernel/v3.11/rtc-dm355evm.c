static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
union V_5 time ;
int V_6 ;
int V_7 = 0 ;
do {
V_6 = F_2 ( V_8 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( V_7 && time . V_9 [ 0 ] == V_6 )
break;
time . V_9 [ 0 ] = V_6 ;
V_6 = F_2 ( V_10 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( V_7 && time . V_9 [ 1 ] == V_6 )
break;
time . V_9 [ 1 ] = V_6 ;
V_6 = F_2 ( V_11 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( V_7 && time . V_9 [ 2 ] == V_6 )
break;
time . V_9 [ 2 ] = V_6 ;
V_6 = F_2 ( V_12 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( V_7 && time . V_9 [ 3 ] == V_6 )
break;
time . V_9 [ 3 ] = V_6 ;
} while ( ++ V_7 < 5 );
F_3 ( V_2 , L_1 , time . V_13 ) ;
F_4 ( F_5 ( time . V_13 ) , V_4 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
union V_5 time ;
unsigned long V_13 ;
int V_6 ;
F_7 ( V_4 , & V_13 ) ;
time . V_13 = F_8 ( V_13 ) ;
F_3 ( V_2 , L_2 , time . V_13 ) ;
V_6 = F_9 ( time . V_9 [ 0 ] , V_8 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_9 ( time . V_9 [ 1 ] , V_10 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_9 ( time . V_9 [ 2 ] , V_11 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_9 ( time . V_9 [ 3 ] , V_12 ) ;
if ( V_6 < 0 )
return V_6 ;
return 0 ;
}
static int F_10 ( struct V_14 * V_15 )
{
struct V_16 * V_17 ;
V_17 = F_11 ( & V_15 -> V_2 , V_15 -> V_18 ,
& V_19 , V_20 ) ;
if ( F_12 ( V_17 ) ) {
F_13 ( & V_15 -> V_2 , L_3 ,
F_14 ( V_17 ) ) ;
return F_14 ( V_17 ) ;
}
F_15 ( V_15 , V_17 ) ;
return 0 ;
}
