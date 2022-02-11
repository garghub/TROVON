void F_1 ( struct V_1 * V_1 )
{
F_2 (
new.count++;
,
return;
) ;
F_3 ( & V_1 -> V_2 ) ;
V_1 -> V_3 ++ ;
F_4 ( & V_1 -> V_2 ) ;
}
int F_5 ( struct V_1 * V_1 )
{
int V_4 ;
F_2 (
new.count++;
if (old.count <= 0)
return 0;
,
return 1;
) ;
F_3 ( & V_1 -> V_2 ) ;
V_4 = 0 ;
if ( V_1 -> V_3 > 0 ) {
V_1 -> V_3 ++ ;
V_4 = 1 ;
}
F_4 ( & V_1 -> V_2 ) ;
return V_4 ;
}
int F_6 ( struct V_1 * V_1 )
{
F_2 (
new.count++;
if (old.count <= 0)
break;
,
return 1;
) ;
F_3 ( & V_1 -> V_2 ) ;
if ( V_1 -> V_3 <= 0 )
return 0 ;
V_1 -> V_3 ++ ;
F_4 ( & V_1 -> V_2 ) ;
return 1 ;
}
int F_7 ( struct V_1 * V_1 )
{
F_2 (
new.count--;
if (old.count <= 0)
return -1;
,
return new.count;
) ;
return - 1 ;
}
int F_8 ( struct V_1 * V_1 )
{
F_2 (
new.count--;
if (old.count <= 1)
break;
,
return 1;
) ;
F_3 ( & V_1 -> V_2 ) ;
if ( V_1 -> V_3 <= 1 )
return 0 ;
V_1 -> V_3 -- ;
F_4 ( & V_1 -> V_2 ) ;
return 1 ;
}
void F_9 ( struct V_1 * V_1 )
{
F_10 ( & V_1 -> V_2 ) ;
V_1 -> V_3 = - 128 ;
}
int F_11 ( struct V_1 * V_1 )
{
int V_4 ;
F_2 (
new.count++;
if (old.count < 0)
return 0;
,
return 1;
) ;
F_3 ( & V_1 -> V_2 ) ;
V_4 = 0 ;
if ( V_1 -> V_3 >= 0 ) {
V_1 -> V_3 ++ ;
V_4 = 1 ;
}
F_4 ( & V_1 -> V_2 ) ;
return V_4 ;
}
