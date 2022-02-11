static char * T_1 F_1 ( char * V_1 , int V_2 , char * V_3 )
{
if( ! V_2 )
return V_3 ;
V_2 -- ;
while( * V_3 )
{
if( * V_3 == ',' )
{
V_3 ++ ;
break;
}
else if( * V_3 == '\"' )
{
V_3 ++ ;
while( * V_3 )
{
if( * V_3 == '\"' )
{
V_3 ++ ;
break;
}
* V_1 = * V_3 ;
V_1 ++ ;
V_3 ++ ;
V_2 -- ;
if( ! V_2 )
{
* V_1 = 0 ;
return V_3 ;
}
}
}
else
{
* V_1 = * V_3 ;
V_1 ++ ;
V_3 ++ ;
V_2 -- ;
if( ! V_2 )
{
* V_1 = 0 ;
return V_3 ;
}
}
}
* V_1 = 0 ;
return V_3 ;
}
static int T_1 F_2 ( char * line )
{
char string [ V_4 ] ;
int V_5 [ 6 ] ;
F_3 ( F_1 ( string , sizeof( string ) , line ) , 6 , V_5 ) ;
if( V_5 [ 0 ] < 1 )
{
F_4 ( V_6 L_1
L_2 ) ;
return 1 ;
}
if( ( V_5 [ 1 ] < 0 ) || ( V_5 [ 1 ] >= V_7 ) )
{
F_4 ( V_6 L_3 ,
V_5 [ 1 ] , V_7 - 1 ) ;
return 1 ;
}
memset ( & V_8 [ V_5 [ 1 ] ] , 0 , sizeof( V_8 [ V_5 [ 1 ] ] ) ) ;
memcpy ( & V_8 [ V_5 [ 1 ] ] . V_9 ,
& V_10 , sizeof( V_8 [ V_5 [ 1 ] ] . V_9 ) ) ;
V_11 [ V_5 [ 1 ] ] = 1 ;
V_8 [ V_5 [ 1 ] ] . V_12 = V_13 ;
V_8 [ V_5 [ 1 ] ] . V_14 = 2 ;
V_8 [ V_5 [ 1 ] ] . V_15 = NULL ;
V_8 [ V_5 [ 1 ] ] . V_9 . V_16 = V_8 [ V_5 [ 1 ] ] . V_17 ;
strcpy ( V_8 [ V_5 [ 1 ] ] . V_9 . V_16 , string ) ;
if( V_5 [ 0 ] > 1 )
{
V_8 [ V_5 [ 1 ] ] . V_12 = V_5 [ 2 ] ;
}
if( V_5 [ 0 ] > 2 )
{
V_8 [ V_5 [ 1 ] ] . V_9 . V_18 = V_5 [ 3 ] ;
}
if( V_5 [ 0 ] > 3 )
{
V_8 [ V_5 [ 1 ] ] . V_9 . V_19 = V_5 [ 4 ] ;
}
if( V_5 [ 0 ] > 4 )
{
V_8 [ V_5 [ 1 ] ] . V_14 = V_5 [ 5 ] ;
}
return 1 ;
}
static int T_1 F_5 ( char * line )
{
char string [ V_4 ] ;
int V_5 [ 4 ] ;
F_3 ( F_1 ( string , sizeof( string ) , line ) , 4 , V_5 ) ;
if( V_5 [ 0 ] < 3 )
{
F_4 ( V_6 L_4
L_5 ) ;
return 1 ;
}
if( ( V_5 [ 1 ] < 0 ) || ( V_5 [ 1 ] >= V_7 ) )
{
F_4 ( V_6 L_3 ,
V_5 [ 1 ] , V_7 - 1 ) ;
return 1 ;
}
if( V_20 [ V_5 [ 1 ] ] >= V_21 )
{
F_4 ( V_6 L_6 ) ;
return 1 ;
}
V_8 [ V_5 [ 1 ] ] . V_22 [ V_20 [ V_5 [ 1 ] ] ] . V_16 =
V_8 [ V_5 [ 1 ] ] . V_23 [ V_20 [ V_5 [ 1 ] ] ] ;
strcpy ( V_8 [ V_5 [ 1 ] ] . V_22 [ V_20 [ V_5 [ 1 ] ] ] . V_16 , string ) ;
V_8 [ V_5 [ 1 ] ] . V_22 [ V_20 [ V_5 [ 1 ] ] ] . V_18 =
V_5 [ 2 ] ;
V_8 [ V_5 [ 1 ] ] . V_22 [ V_20 [ V_5 [ 1 ] ] ] . V_24 =
V_5 [ 3 ] ;
V_8 [ V_5 [ 1 ] ] . V_22 [ V_20 [ V_5 [ 1 ] ] ] . V_25 = 0 ;
V_20 [ V_5 [ 1 ] ] ++ ;
return 1 ;
}
static int T_1 F_6 ( void )
{
int V_26 , V_27 ;
for( V_27 = V_26 = 0 ; V_26 < V_7 ; V_26 ++ )
{
if( V_20 [ V_26 ] && ( ! V_11 [ V_26 ] ) )
{
F_4 ( V_6 L_7 ,
V_26 ) ;
memset ( & V_8 [ V_26 ] , 0 , sizeof( V_8 [ V_26 ] ) ) ;
memcpy ( & V_8 [ V_26 ] . V_9 , & V_10 ,
sizeof( V_8 [ V_26 ] . V_9 ) ) ;
V_11 [ V_26 ] = 1 ;
V_8 [ V_26 ] . V_12 = V_13 ;
V_8 [ V_26 ] . V_14 = 2 ;
V_8 [ V_26 ] . V_15 = NULL ;
V_8 [ V_26 ] . V_9 . V_16 = V_8 [ V_26 ] . V_17 ;
strcpy ( V_8 [ V_26 ] . V_9 . V_16 , L_8 ) ;
}
if( V_11 [ V_26 ] )
{
V_27 ++ ;
F_4 (KERN_NOTICE MTD_FORTUNET_PK L_9
L_10 ,
map_regions[ix].map_info.name,
map_regions[ix].window_addr_physical,
map_regions[ix].map_info.size) ;
V_8 [ V_26 ] . V_9 . V_28 = V_8 [ V_26 ] . V_12 ,
V_8 [ V_26 ] . V_9 . V_29 =
F_7 (
V_8 [ V_26 ] . V_12 ,
V_8 [ V_26 ] . V_9 . V_18 ) ;
if( ! V_8 [ V_26 ] . V_9 . V_29 )
{
int V_30 = 0 ;
F_4 ( V_6 L_11 ,
V_8 [ V_26 ] . V_9 . V_16 ) ;
for ( V_30 = 0 ; V_30 < V_26 ; V_30 ++ )
F_8 ( V_8 [ V_30 ] . V_9 . V_29 ) ;
return - V_31 ;
}
F_9 ( & V_8 [ V_26 ] . V_9 ) ;
F_4 (KERN_NOTICE MTD_FORTUNET_PK L_12 ,
map_regions[ix].map_info.name,
map_regions[ix].map_info.virt) ;
V_8 [ V_26 ] . V_15 = F_10 ( L_13 ,
& V_8 [ V_26 ] . V_9 ) ;
if( ( ! V_8 [ V_26 ] . V_15 ) && (
V_8 [ V_26 ] . V_14 != V_8 [ V_26 ] . V_9 . V_19 ) )
{
F_4 (KERN_NOTICE MTD_FORTUNET_PK L_14
L_15 ,
map_regions[ix].map_info.name) ;
V_8 [ V_26 ] . V_9 . V_19 =
V_8 [ V_26 ] . V_14 ;
V_8 [ V_26 ] . V_15 = F_10 ( L_13 ,
& V_8 [ V_26 ] . V_9 ) ;
}
V_8 [ V_26 ] . V_15 -> V_32 = V_33 ;
F_11 ( V_8 [ V_26 ] . V_15 ,
V_8 [ V_26 ] . V_22 ,
V_20 [ V_26 ] ) ;
}
}
if( V_27 )
return 0 ;
return - V_31 ;
}
static void T_2 F_12 ( void )
{
int V_26 ;
for( V_26 = 0 ; V_26 < V_7 ; V_26 ++ )
{
if( V_11 [ V_26 ] )
{
if( V_8 [ V_26 ] . V_15 )
{
F_13 ( V_8 [ V_26 ] . V_15 ) ;
F_14 ( V_8 [ V_26 ] . V_15 ) ;
}
F_8 ( ( void * ) V_8 [ V_26 ] . V_9 . V_29 ) ;
}
}
}
