static int F_1 ( int V_1 , const char * * V_2 )
{
int V_3 , V_4 = 0 , V_5 ;
const char * * V_6 ;
V_3 = V_1 + 2 ;
V_6 = calloc ( V_3 + 1 , sizeof( char * ) ) ;
V_6 [ V_4 ++ ] = F_2 ( L_1 ) ;
V_6 [ V_4 ++ ] = F_2 ( L_2 ) ;
V_6 [ V_4 ++ ] = F_2 ( V_7 ) ;
for ( V_5 = 1 ; V_5 < V_1 ; V_5 ++ , V_4 ++ )
V_6 [ V_4 ] = V_2 [ V_5 ] ;
F_3 ( V_4 != V_3 ) ;
return F_4 ( V_4 , V_6 , NULL ) ;
}
static int F_5 ( int V_1 , const char * * V_2 )
{
int V_3 , V_4 = 0 , V_5 ;
const char * * V_6 ;
V_3 = V_1 + 2 ;
V_6 = calloc ( V_3 + 1 , sizeof( char * ) ) ;
V_6 [ V_4 ++ ] = F_2 ( L_3 ) ;
V_6 [ V_4 ++ ] = F_2 ( L_4 ) ;
V_6 [ V_4 ++ ] = F_2 ( V_7 ) ;
for ( V_5 = 1 ; V_5 < V_1 ; V_5 ++ , V_4 ++ )
V_6 [ V_4 ] = V_2 [ V_5 ] ;
F_3 ( V_4 != V_3 ) ;
return F_6 ( V_4 , V_6 , NULL ) ;
}
static int F_7 ( int V_1 , const char * * V_2 )
{
int V_3 , V_4 = 0 , V_5 ;
const char * * V_6 ;
V_3 = V_1 + 2 ;
V_6 = calloc ( V_3 + 1 , sizeof( char * ) ) ;
V_6 [ V_4 ++ ] = F_2 ( L_5 ) ;
V_6 [ V_4 ++ ] = F_2 ( L_4 ) ;
V_6 [ V_4 ++ ] = F_2 ( V_7 ) ;
for ( V_5 = 1 ; V_5 < V_1 ; V_5 ++ , V_4 ++ )
V_6 [ V_4 ] = V_2 [ V_5 ] ;
F_3 ( V_4 != V_3 ) ;
return F_8 ( V_4 , V_6 , NULL ) ;
}
int F_9 ( int V_1 , const char * * V_2 , const char * T_1 V_8 )
{
V_9 = V_10 = 0 ;
V_1 = F_10 ( V_1 , V_2 , V_11 , V_12 ,
V_13 ) ;
if ( ! V_1 )
F_11 ( V_12 , V_11 ) ;
if ( ! V_9 )
V_10 = 1 ;
if ( ! V_7 ) {
if ( V_9 && ! V_10 )
sprintf ( V_14 , L_6 ) ;
else if ( ! V_9 && V_10 )
sprintf ( V_14 , L_7 ) ;
else
sprintf ( V_14 , L_8 ) ;
V_7 = V_14 ;
}
if ( ! strncmp ( V_2 [ 0 ] , L_9 , 3 ) )
return F_1 ( V_1 , V_2 ) ;
else if ( ! strncmp ( V_2 [ 0 ] , L_10 , 3 ) )
return F_5 ( V_1 , V_2 ) ;
else if ( ! strncmp ( V_2 [ 0 ] , L_11 , 4 ) )
return F_12 ( V_1 , V_2 , NULL ) ;
else if ( ! strncmp ( V_2 [ 0 ] , L_12 , 3 ) )
return F_13 ( V_1 , V_2 , NULL ) ;
else if ( ! strncmp ( V_2 [ 0 ] , L_5 , 12 ) )
return F_7 ( V_1 , V_2 ) ;
else
F_11 ( V_12 , V_11 ) ;
return 0 ;
}
